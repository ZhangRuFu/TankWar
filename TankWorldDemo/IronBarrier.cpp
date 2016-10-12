#include "IronBarrier.h"

IronBarrier::IronBarrier(Vector2D & position, GameWorld *gameWorld) : Barrier(position, 100, 100, gameWorld), IRigid(40, 40)
{

}

iRect IronBarrier::GetRigidBody(void)
{
	return iRect(m_position.getX() - m_rigidWidth / 2, m_position.getY() - m_rigidHeight / 2, m_rigidWidth, m_rigidHeight);
}

void IronBarrier::CollisionEvent(IRigid * collisionTarget, Vector2D position)
{
	//Ìú¿éµÄÅö×²´¦Àí
}
