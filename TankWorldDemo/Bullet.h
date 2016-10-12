#pragma once
#include "TSoul.h"
#include "IRigid.h"

class Bullet : public TSoul, public IRigid
{
private:
	//子弹杀伤力
	int m_power;
	//子弹归属者
	enum BulletOwner m_owner;
	//子弹类型
	enum BulletType m_type ;

public:
	Bullet(Vector2D &position, BulletOwner owner, BulletType type, Direction direction, GameWorld *gameWorld) ;
	void Move() ;
	
	//实现刚体接口
	virtual iRect GetRigidBody(void);
	virtual void CollisionEvent(IRigid *collisionTarget, Vector2D position);
};