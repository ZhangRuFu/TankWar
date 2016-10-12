#include "BrickBarrier.h"

BrickBarrier::BrickBarrier(Vector2D & position, GameWorld *gameWorld) : Barrier(position, 100, 0, gameWorld), IRigid(40, 40)
{

}

iRect BrickBarrier::GetRigidBody(void)
{
	return iRect(m_position.getX() - m_rigidWidth / 2, m_position.getY() - m_rigidHeight / 2, m_rigidWidth, m_rigidHeight);
}

void BrickBarrier::CollisionEvent(IRigid * collisionTarget, Vector2D position)
{
	//×©¿éµÄÅö×²´¦Àí
}