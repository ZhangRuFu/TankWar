#include "Tank.h"
#include "Bullet.h"
#include "GameWorld.h"
#include "CollisionManager.h"
#include "ResourceManager.h"
#include <typeinfo>

Tank::Tank(Vector2D & position, int health, int defense, int apperanceWidth, int apperanceHeight, Direction direction, int speed, GameWorld *gameWorld)
	: TSoul(position, health, defense, gameWorld, direction, speed)
	, IRigid(40, 40)
	, m_oldPosition(position)
{

}

iRect Tank::GetRigidBody(void)
{
	//获取碰撞检测矩形
	iRect rect(m_position.getX() - m_rigidWidth / 2, m_position.getY() - m_rigidHeight / 2, m_rigidWidth, m_rigidHeight);
	return rect;
}

void Tank::Move(void)
{
	//如果当前行为状态为 停止 ，直接返回无操作
	if (m_behavoirState == BehavoirState::Stop)
		return;

	m_oldPosition = m_position;
	switch (m_direction)
	{
	case Direction::Up:
		m_position.ReduceY(m_speed);
		break;
	case Direction::Down:
		m_position.AddY(m_speed);
		break;
	case Direction::Left:
		m_position.ReduceX(m_speed);
		break;
	case Direction::Right:
		m_position.AddX(m_speed);
		break;
	default:
		break;
	}

	m_gameWorld->CollisionDectect(this);
	m_behavoirState = BehavoirState::Stop;
}