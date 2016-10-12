#include "CollisionManager.h"
#include "SoulManager.h"
#include "IRigid.h"
#include "Bullet.h"
#include "PlayerTank.h"
#include "EnemyTank.h"
#include "GameWorld.h"
#include "View.h"
#include "TObject.h"
#include <typeinfo>
#include <windows.h>

CollisionManager::CollisionManager(ManagerGroup *managerGroup)
{
	m_managerGroup = managerGroup;
}

void CollisionManager::RegisterRigid(IRigid * rigid)
{
	if (rigid == nullptr)
		return;
	m_rigidList.push_back(rigid);
}

void CollisionManager::DeleteRigid(IRigid * rigid)
{
	m_rigidList.remove(rigid);
}

bool CollisionManager::IsOccupied(IRigid * rigid)
{
	iRect rect = rigid->GetRigidBody();
	RECT srcRect = rect;
	RECT collsionArea;
	//遍历刚体list,判断是否发生占据
	list<IRigid*>::iterator i;
	for (i = m_rigidList.begin(); i != m_rigidList.end(); i++)
	{
		RECT destRect = (*i)->GetRigidBody();
		if (IntersectRect(&collsionArea, &srcRect, &destRect))
			return true;
	}
	return false;
}

void CollisionManager::CollisionDectect(IRigid * rigid)
{
	//获取	
	iRect rect = rigid->GetRigidBody();
	RECT srcRect = rect;
	RECT collsionArea;

	//边界检测
	if (rect.m_x < 0 || rect.m_y < 0 || rect.m_x + rect.m_width - 1> View::m_screenWidth || rect.m_y + rect.m_height - 1 > View::m_screenHeight)
	{
		rigid->CollisionEvent(nullptr, Vector2D(0, 0));
		DeadDectect(rigid);
		return;
	}
	
	//遍历刚体list,找到碰撞的刚体
	list<IRigid*>::iterator i;
	for (i = m_rigidList.begin(); i != m_rigidList.end(); i++)
	{
		if (rigid == *i)
			continue;
		RECT destRect = (*i)->GetRigidBody();
		if (IntersectRect(&collsionArea, &srcRect, &destRect))
		{
			//发生了碰撞
			//通知刚体
			Vector2D v((collsionArea.right - collsionArea.left) / 2, (collsionArea.bottom - collsionArea.top) / 2);
			rigid->CollisionEvent(*i, v);
			(*i)->CollisionEvent(rigid, v);
			//如果死亡，跳出这个循环,删除操作交给SoulManager的下次MoveAll做
			if (DeadDectect(rigid))
				break;
		}
	}
}

bool CollisionManager::DeadDectect(IRigid * rigid)
{
	//这里不动态转换好像会出错
	TObject *obj = dynamic_cast<TObject*>(rigid);
	return obj->isDead();
}