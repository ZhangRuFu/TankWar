#include "HomeBarrier.h"

HomeBarrier::HomeBarrier(GameWorld * gameWorld) : Barrier(Vector2D(300, 570), 100, 0, gameWorld), IRigid(40, 40)
{

}

iRect HomeBarrier::GetRigidBody(void)
{
	return iRect(m_position.getX() - m_rigidWidth / 2, m_position.getY() - m_rigidHeight / 2, m_rigidWidth, m_rigidHeight);
}

void HomeBarrier::CollisionEvent(IRigid * collisionTarget, Vector2D position)
{
}
