//精灵资源管理器的实现文件
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
	//剩余敌人数
	m_restCount = 10;

	//产生玩家坦克
	m_playerTank = new PlayerTank(3, m_managerGroup->GetGameWorld());
	//玩家坦克注册刚体
	RegisterRigid(m_playerTank);
}

void SoulManager::RegisterSoul(TSoul *soul)
{
	//类型判断
	if (typeid(*soul) == typeid(Bullet))
	{
		//子弹类型
		m_bullet.push_back((Bullet*)soul);
		RegisterRigid((Bullet*)soul);
	}
}

//添加敌军坦克
void SoulManager::AddEnemyTank(void)
{
	if (m_restCount)
	{
		Direction randDir = (Direction)(rand() % 3);
		//选择出生点
		int birthIndex = rand() % 2;
		//int randSpeed = rand() % 8;//产生0~8的随机速度
		EnemyTank *enemyTank = new EnemyTank(m_enemyBirthPoint[birthIndex], randDir, EnemyTankType::Normal, m_managerGroup->GetGameWorld());
		//检查出点点是否被占据
		if (m_managerGroup->GetCollisionManager()->IsOccupied(enemyTank))
		{
			//重置出生点
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
	//遍历queue和玩家坦克，进行移动
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
	
	//遍历子弹list进行移动
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
	//遍历queue和玩家坦克，进行绘制
	for (list<EnemyTank*>::iterator i = m_aliveEnemyTank.begin(); i != m_aliveEnemyTank.end(); i++)
		view->DrawGameElement(*i);

	//绘制玩家坦克
	view->DrawGameElement(m_playerTank);

	//遍历子弹list进行绘制
	for (list<Bullet*>::iterator i = m_bullet.begin(); i != m_bullet.end(); i++)
		view->DrawGameElement(*i);
	
}
