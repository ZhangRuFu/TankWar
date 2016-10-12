#pragma once
#include "Barrier.h"
#include "IRigid.h"

class IronBarrier : public Barrier, public IRigid
{
private:

public:
	IronBarrier(Vector2D &position, GameWorld *gameWorld) ;

public:
	virtual iRect GetRigidBody(void);
	virtual void CollisionEvent(IRigid *collisionTarget, Vector2D position);
};