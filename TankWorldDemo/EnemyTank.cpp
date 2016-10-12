#include "EnemyTank.h"
#include "View.h"
#include "Bullet.h"
#include "GameWorld.h"
#include <typeinfo>

EnemyTank::EnemyTank(Vector2D &position, Direction &direction, EnemyTankType type, GameWorld *gameWorld) : Tank(position, 100, 0, 40, 40, direction, 10, gameWorld)
{
	m_lastTime = rand() % 400;
	m_delayTime = 400;
}

void EnemyTank::CollisionEvent(IRigid *collisionTarget, Vector2D position)
{
	//����̹��������ײ������
	//����������˴���
	if (collisionTarget == nullptr)
	{
		m_position = m_oldPosition;
		return;
	}
	if (typeid(*collisionTarget) == typeid(Bullet))
		return;
	m_position = m_oldPosition;
	return;
}

void EnemyTank::Move(void)
{
	if (m_lastTime < m_delayTime)
	{
		m_lastTime += m_gameWorld->getDelayTime();
		return;
	}
	else
		m_lastTime = 0;

	m_oldPosition = m_position;
	int behaviorJudge = rand() % 100;//����0~100֮����������Ϊ�б�ʶ
	if (behaviorJudge <= 3)    //3%�ĸ��ʸı䷽��
	{
		m_direction = (Direction)behaviorJudge;
		return;
	}
	else if (behaviorJudge < 20)  //27%���ʷ����ӵ� 
	{
		Fire();
		return;
	}
	else
	{
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
	}
	m_gameWorld->CollisionDectect(this);
}

void EnemyTank::Fire(void)
{
	Bullet *bullet = new Bullet(m_position, BulletOwner::Enemy, BulletType::Small, m_direction, m_gameWorld);
	m_gameWorld->AddSoul(bullet);
}

