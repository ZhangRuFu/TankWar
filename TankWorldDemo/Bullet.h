#pragma once
#include "TSoul.h"
#include "IRigid.h"

class Bullet : public TSoul, public IRigid
{
private:
	//�ӵ�ɱ����
	int m_power;
	//�ӵ�������
	enum BulletOwner m_owner;
	//�ӵ�����
	enum BulletType m_type ;

public:
	Bullet(Vector2D &position, BulletOwner owner, BulletType type, Direction direction, GameWorld *gameWorld) ;
	void Move() ;
	
	//ʵ�ָ���ӿ�
	virtual iRect GetRigidBody(void);
	virtual void CollisionEvent(IRigid *collisionTarget, Vector2D position);
};