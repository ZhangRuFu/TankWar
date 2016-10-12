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
	//��������list,�ж��Ƿ���ռ��
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
	//��ȡ	
	iRect rect = rigid->GetRigidBody();
	RECT srcRect = rect;
	RECT collsionArea;

	//�߽���
	if (rect.m_x < 0 || rect.m_y < 0 || rect.m_x + rect.m_width - 1> View::m_screenWidth || rect.m_y + rect.m_height - 1 > View::m_screenHeight)
	{
		rigid->CollisionEvent(nullptr, Vector2D(0, 0));
		DeadDectect(rigid);
		return;
	}
	
	//��������list,�ҵ���ײ�ĸ���
	list<IRigid*>::iterator i;
	for (i = m_rigidList.begin(); i != m_rigidList.end(); i++)
	{
		if (rigid == *i)
			continue;
		RECT destRect = (*i)->GetRigidBody();
		if (IntersectRect(&collsionArea, &srcRect, &destRect))
		{
			//��������ײ
			//֪ͨ����
			Vector2D v((collsionArea.right - collsionArea.left) / 2, (collsionArea.bottom - collsionArea.top) / 2);
			rigid->CollisionEvent(*i, v);
			(*i)->CollisionEvent(rigid, v);
			//����������������ѭ��,ɾ����������SoulManager���´�MoveAll��
			if (DeadDectect(rigid))
				break;
		}
	}
}

bool CollisionManager::DeadDectect(IRigid * rigid)
{
	//���ﲻ��̬ת����������
	TObject *obj = dynamic_cast<TObject*>(rigid);
	return obj->isDead();
}