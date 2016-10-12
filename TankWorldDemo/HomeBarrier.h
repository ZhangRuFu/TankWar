#pragma once
#include "Barrier.h"
#include "IRigid.h"

class HomeBarrier : public Barrier, public IRigid
{
private:

public:
	HomeBarrier(GameWorld *gameWorld);
	virtual iRect GetRigidBody(void);
	virtual void CollisionEvent(IRigid *collisionTarget, Vector2D position);
};