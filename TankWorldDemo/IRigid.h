#pragma once
#include "Global.h"
class TObject;
class IRigid
{
protected:
	int m_rigidWidth ;
	int m_rigidHeight ;
public:
	IRigid(int rigidWidth, int rigidHeight) ;
	//��ȡ�����Χ����
	virtual iRect GetRigidBody(void) = 0;
	//����ֳ� ������ײ �� ������ײ��ò��ûʲô��.........
	//������ײ�¼�������(������ײ)
	//virtual void PositiveCollisionEvent(IRigid *collisionTarget, Vector2D position) = 0 ;
	//������ײ�¼�������(������ײ)
	//virtual void PassitiveCollisionEvent(IRigid *collisionSource, Vector2D position) = 0;
	virtual void CollisionEvent(IRigid *collisionTarget, Vector2D position) = 0;
};