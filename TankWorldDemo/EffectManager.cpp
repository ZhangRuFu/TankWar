#include "EffectManager.h"
#include "ResourceManager.h"
#include "SoulManager.h"
#include "ManagerGroup.h"
#include "View.h"

//爆炸特效
Effect::Effect(Vector2D position) : m_position(position)
{
	m_currentFrame = 0;
	m_isDead = false;
}

bool Effect::IsDead(void)
{
	return m_isDead;
}

int Effect::getCurrentFrame(void)
{
	return m_currentFrame;
}

Vector2D Effect::getPosition(void)
{
	return m_position;
}

//爆炸特效
Bomb::Bomb(Vector2D bombPosition, BombStyle style) : Effect(bombPosition)
{
	m_bombStyle = style;
}

void Bomb::Move(void)
{
	int maxFrame = m_bombStyle == BombStyle::SmallBomb ? m_smallFrame : m_bigFrame;
	++m_currentFrame;
	if (m_currentFrame >= maxFrame)
		m_isDead = true;
}

//出生特效
Birth::Birth(Vector2D birthPosition) : Effect(birthPosition)
{
	m_loop = 3;
}

void Birth::Move(void)
{
	++m_currentFrame;
	if (m_currentFrame >= m_maxFrame)
	{
		if (m_loop)
		{
			--m_loop;
			m_currentFrame = 0;
		}
		else
			m_isDead = true;
	}
}


//特效管理器
EffectManager::EffectManager(ManagerGroup *managerGroup)
{
	m_managerGroup = managerGroup;
}

void EffectManager::AddBomb(Vector2D bombPosition, BombStyle style)
{
	m_bombList.push_back(new Bomb(bombPosition, style));
}

void EffectManager::AddBirth(Vector2D birthPosition)
{
	m_birthList.push_back(new Birth(birthPosition));
}

void EffectManager::DrawEffect(void)
{
	static View *view = m_managerGroup->GetView();
	for (list<Bomb*>::iterator i = m_bombList.begin(); i != m_bombList.end(); i++)
		view->DrawEffectElement(*i);
	for (list<Birth*>::iterator i = m_birthList.begin(); i != m_birthList.end();i++)
		view->DrawEffectElement(*i);
}

void EffectManager::Move(void)
{
	for (list<Bomb*>::iterator i = m_bombList.begin(); i != m_bombList.end(); )
	{
		if ((*i)->IsDead())
			i = m_bombList.erase(i);
		else
		{
			(*i)->Move();
			i++;
		}
	}

	for (list<Birth*>::iterator i = m_birthList.begin(); i != m_birthList.end();)
	{
		if ((*i)->IsDead())
		{
			i = m_birthList.erase(i);
			m_managerGroup->GetSoulManager()->EffectFinish();
		}
		else
		{
			(*i)->Move();
			i++;
		}
	}
}

int Bomb::m_bigFrame = 7;
int Bomb::m_smallFrame = 3;
int Birth::m_maxFrame = 6;