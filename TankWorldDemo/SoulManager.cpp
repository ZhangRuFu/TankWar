//������Դ��������ʵ���ļ�
#include "SoulManager.h"
#include "GameWorld.h"
#include "PlayerTank.h"
#include "EnemyTank.h"
#include "Bullet.h"
#include "View.h"
#include "ResourceManager.h"
#include "CollisionManager.h"
#include "EffectManager.h"
#include "ManagerGroup.h"
#include <typeinfo>

SoulManager::SoulManager(ManagerGroup *managerGroup) : m_enemyBirthPoint{Vector2D(30, 30), Vector2D(570, 30)}
{
	m_managerGroup = managerGroup;
	m_restCount = 0;
}

PlayerTank * SoulManager::getPlayerTank(void)
{
	return m_playerTank;
}

int SoulManager::getRestCount(void)
{
	return m_restCount;
}

void SoulManager::RegisterSoul()
{		
	//ʣ�������
	m_restCount = 10;

	//�������̹��
	m_playerTank = new PlayerTank(3, m_managerGroup->GetGameWorld());
	//���̹��ע�����
	RegisterRigid(m_playerTank);
}

void SoulManager::RegisterSoul(TSoul *soul)
{
	//�����ж�
	if (typeid(*soul) == typeid(Bullet))
	{
		//�ӵ�����
		m_bullet.push_back((Bullet*)soul);
		RegisterRigid((Bullet*)soul);
	}
}

//��ӵо�̹��
void SoulManager::AddEnemyTank(void)
{
	if (m_restCount)
	{
		Direction randDir = (Direction)(rand() % 3);
		//ѡ�������
		int birthIndex = rand() % 2;
		//int randSpeed = rand() % 8;//����0~8������ٶ�
		EnemyTank *enemyTank = new EnemyTank(m_enemyBirthPoint[birthIndex], randDir, EnemyTankType::Normal, m_managerGroup->GetGameWorld());
		//��������Ƿ�ռ��
		if (m_managerGroup->GetCollisionManager()->IsOccupied(enemyTank))
		{
			//���ó�����
			enemyTank->setPosition(enemyTank->getPosition() == m_enemyBirthPoint[0] ? m_enemyBirthPoint[1] : m_enemyBirthPoint[0]);
			return;
		}
		m_managerGroup->GetEffectManager()->AddBirth(enemyTank->getPosition());
		m_birthEnemyTank.push_back(enemyTank);
		RegisterRigid(enemyTank);
	}
}

void SoulManager::RegisterRigid(IRigid * rigid)
{
	m_managerGroup->GetCollisionManager()->RegisterRigid(rigid);
}

void SoulManager::DeleteRigid(IRigid * rigid)
{
	m_managerGroup->GetCollisionManager()->DeleteRigid(rigid);
}

void SoulManager::EffectFinish(void)
{
	m_aliveEnemyTank.push_back(m_birthEnemyTank.front());
	m_birthEnemyTank.pop_front();
}

void SoulManager::MoveAll(void)
{
	if (m_aliveEnemyTank.size() < m_maxAliveTank)
		AddEnemyTank();
	//����queue�����̹�ˣ������ƶ�
	for (list<EnemyTank*>::iterator i = m_aliveEnemyTank.begin(); i != m_aliveEnemyTank.end(); )
	{
		if ((*i)->isDead())
		{
			m_managerGroup->GetEffectManager()->AddBomb((*i)->getPosition());
			DeleteRigid(*i);
			delete(*i);
			i = m_aliveEnemyTank.erase(i);
			--m_restCount;
		}
		else
		{
			(*i)->Move();
			i++;
		}
	}

	if (m_playerTank->isDead())
	{
		if (m_playerTank->hasLife())
			m_playerTank->Resurrect();
		else
		{
			m_managerGroup->GetGameWorld()->GameOver();
			return;
		}
	}
	m_playerTank->Move();
	
	//�����ӵ�list�����ƶ�
	for (list<Bullet*>::iterator i = m_bullet.begin(); i != m_bullet.end(); )
	{
		if ((*i)->isDead())
		{
			m_managerGroup->GetEffectManager()->AddBomb((*i)->getPosition(), BombStyle::SmallBomb);
			DeleteRigid(*i);
			delete(*i);
			i = m_bullet.erase(i);
		}
		else
		{
			(*i)->Move();
			i++;
		}
	}
}
void SoulManager::DrawAll(void)
{
	static View *view = m_managerGroup->GetView();
	//����queue�����̹�ˣ����л���
	for (list<EnemyTank*>::iterator i = m_aliveEnemyTank.begin(); i != m_aliveEnemyTank.end(); i++)
		view->DrawGameElement(*i);

	//�������̹��
	view->DrawGameElement(m_playerTank);

	//�����ӵ�list���л���
	for (list<Bullet*>::iterator i = m_bullet.begin(); i != m_bullet.end(); i++)
		view->DrawGameElement(*i);
	
}
