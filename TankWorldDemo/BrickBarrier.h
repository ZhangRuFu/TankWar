#pragma once
#include "Barrier.h"
#include "IRigid.h"

class BrickBarrier : public Barrier, public IRigid
{
private:

public:
	BrickBarrier(Vector2D &position, GameWorld *gameWorld) ;
	virtual iRect GetRigidBody(void);
	virtual void CollisionEvent(IRigid *collisionTarget, Vector2D position);
};