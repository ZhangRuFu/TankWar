//玩家坦克的实现文件
#include "PlayerTank.h"
#include "CollisionManager.h"
#include "Bullet.h"
#include "View.h"
#include "GameWorld.h"
#include <typeinfo>

PlayerTank::PlayerTank(int life, GameWorld *gameWorld) : Tank(Vector2D(260, 550), 100, 0, 40, 40, Direction::Up, 5, gameWorld)
{
	m_life = life;
	m_behavoirState = BehavoirState::Stop;
}

void PlayerTank::CollisionEvent(IRigid *collisionTarget, Vector2D position)
{
	//玩家坦克碰撞到刚体
	//进行坐标回退处理
	if (collisionTarget == nullptr)
	{
		//撞到墙了
		m_position = m_oldPosition;
		return;
	}
	if (typeid(*collisionTarget) == typeid(Bullet))
		return;
	m_position = m_oldPosition;
}


void PlayerTank::Fire(void)
{
	Bullet *bullet = new Bullet(m_position, BulletOwner::Player, BulletType::Small, m_direction, m_gameWorld);
	m_gameWorld->AddSoul(bullet);
}

void PlayerTank::DamageHealth(int value)
{
	TObject::DamageHealth(value);
	if (m_isDead)
		--m_life;
}

bool PlayerTank::hasLife(void)
{
	if (m_life > 0)
		return true;
	return false;
}

void PlayerTank::Drive(Direction direction)
{
	if (direction == m_direction)
		m_behavoirState = BehavoirState::Action;
	else
	{
		m_direction = direction;
	}
}