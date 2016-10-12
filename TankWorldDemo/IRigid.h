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
	//获取刚体包围矩形
	virtual iRect GetRigidBody(void) = 0;
	//这里分成 主动碰撞 和 被动碰撞，貌似没什么用.........
	//积极碰撞事件处理函数(主动碰撞)
	//virtual void PositiveCollisionEvent(IRigid *collisionTarget, Vector2D position) = 0 ;
	//消极碰撞事件处理函数(被动碰撞)
	//virtual void PassitiveCollisionEvent(IRigid *collisionSource, Vector2D position) = 0;
	virtual void CollisionEvent(IRigid *collisionTarget, Vector2D position) = 0;
};