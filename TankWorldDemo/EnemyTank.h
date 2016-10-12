#pragma once
#include "Global.h"
#include "Tank.h"

class EnemyTank : public Tank
{
private:
	//敌军坦克类型
	//不使用继承派生出不同的敌军坦克，而是使用类型会造成什么？
	//不同的坦克只是基本属性不同，外观不同，其余操作基本相同：可能以后扩展某些坦克碰到就产生爆炸
	//优点：减少继承链
	//缺点：需要新增image的list做为外观
	EnemyTankType m_type ;
	int m_delayTime;
	int m_lastTime;
public:
	//访问函数
	Image* getApperance(void);
public:
	EnemyTank(Vector2D& position, Direction& direction, EnemyTankType type, GameWorld *gameWorld);

	//实现刚体接口函数
	virtual void CollisionEvent(IRigid *collisionTarget, Vector2D position);
	virtual void Move(void);

	virtual void Fire(void);
};