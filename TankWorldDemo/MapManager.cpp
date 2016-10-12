//地图资源管理器的实现文件
#include "CollisionManager.h"
#include "ManagerGroup.h"
#include "MapManager.h"
#include "EffectManager.h"
#include "GameWorld.h"
#include "IronBarrier.h"
#include "BrickBarrier.h"
#include "GrassBarrier.h"
#include "HomeBarrier.h"
#include "View.h"
#include "ResourceManager.h"
#include <typeinfo>

MapManager::MapManager(ManagerGroup *managerGroup)
{
	m_managerGroup = managerGroup;
}


void MapManager::RegisterBarrier()
{
	//添加一个铁块
	IronBarrier *ironBarrier = new IronBarrier(Vector2D(150, 150), m_managerGroup->GetGameWorld());
	m_managerGroup->GetCollisionManager()->RegisterRigid(ironBarrier);
	m_ironBarrier.push_back(ironBarrier);

	//添加一个砖块
	BrickBarrier *brickBarrier = new BrickBarrier(Vector2D(400, 150), m_managerGroup->GetGameWorld());
	m_managerGroup->GetCollisionManager()->RegisterRigid(brickBarrier);
	m_brickBarrier.push_back(brickBarrier);

	//添加一个草丛
	GrassBarrier *grassBarrier = new GrassBarrier(Vector2D(150, 250), m_managerGroup->GetGameWorld());
	m_grassBarrier.push_back(grassBarrier);

	//添加一个基地
	m_home = new HomeBarrier(m_managerGroup->GetGameWorld());
	m_managerGroup->GetCollisionManager()->RegisterRigid(m_home);
}

void MapManager::DeleteBarrier(Barrier * barrier)
{
	const type_info &info = typeid(*barrier);
	if (info == typeid(IronBarrier))
		m_ironBarrier.remove((IronBarrier*)barrier);
	else if (info == typeid(BrickBarrier))
		m_brickBarrier.remove((BrickBarrier*)barrier);
	else if (info == typeid(GrassBarrier))
		m_grassBarrier.remove((GrassBarrier*)barrier);
	if (dynamic_cast<IRigid*>(barrier))
		m_managerGroup->GetCollisionManager()->DeleteRigid((IRigid*)barrier);
}

void MapManager::DeleteRigid(IRigid * rigid)
{
	m_managerGroup->GetCollisionManager()->DeleteRigid(rigid);
}

void MapManager::DrawAll()
{
	View *view = m_managerGroup->GetView();
	//遍历三个list，挨个调用Draw()函数
	for (list<IronBarrier*>::iterator i = m_ironBarrier.begin(); i != m_ironBarrier.end(); )
	{
		if ((*i)->isDead())
		{
			m_managerGroup->GetEffectManager()->AddBomb((*i)->getPosition());
			DeleteRigid(*i);
			delete(*i);
			i = m_ironBarrier.erase(i);
		}
		else
		{
			view->DrawGameElement(*i);
			i++;
		}
	}
	for (list<BrickBarrier*>::iterator i = m_brickBarrier.begin(); i != m_brickBarrier.end(); )
	{
		if ((*i)->isDead())
		{
			m_managerGroup->GetEffectManager()->AddBomb((*i)->getPosition());
			DeleteRigid(*i);
			delete(*i);
			i = m_brickBarrier.erase(i);
		}
		else
		{
			view->DrawGameElement(*i);
			i++;
		}
	}
	for (list<GrassBarrier*>::iterator i = m_grassBarrier.begin(); i != m_grassBarrier.end(); i++)
		view->DrawGameElement(*i);

	view->DrawGameElement(m_home);
	if (m_home->isDead())
	{
		m_managerGroup->GetEffectManager()->AddBomb(m_home->getPosition());
		m_managerGroup->GetGameWorld()->GameOver();
	}
}
