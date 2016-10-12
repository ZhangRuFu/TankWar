#include "Bullet.h"
#include "View.h"
#include "CollisionManager.h"
#include "GameWorld.h"
#include "EnemyTank.h"
#include "PlayerTank.h"
#include <typeinfo>

//���캯��
Bullet::Bullet(Vector2D & position, BulletOwner owner, BulletType type, Direction direction, GameWorld *gameWorld) : TSoul(position, 100, 0, gameWorld, direction, 10), IRigid(8, 8)
{
	//����Ӧ�ø����ӵ����ͽ��г�ʼ��������=====================================================
	m_power = 100;
	m_owner = owner;
	m_type = type;
}

//�ӵ���Ҫ�߼�������
void Bullet::Move()
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

	m_gameWorld->CollisionDectect(this);
}

iRect Bullet::GetRigidBody(void)
{
	//��ȡ��ײ������
	int x = m_position.getX();
	int y = m_position.getY();
	int halfWidth = m_rigidWidth / 2;
	int halfHeight = m_rigidHeight / 2;
	iRect rect(x - halfWidth, y - halfHeight, m_rigidWidth, m_rigidHeight);
	return rect;
}

//������ײ����¼�������
void Bullet::CollisionEvent(IRigid * collisionTarget, Vector2D position)
{
	//�ӵ�����ǽ��
	if (collisionTarget == nullptr)
	{
		DamageHealth(100);
		return;
	}
	
	//���������Լ���̹��
	if (m_owner == BulletOwner::Player && typeid(*collisionTarget) == typeid(PlayerTank) || 
		m_owner == BulletOwner::Enemy && typeid(*collisionTarget) == typeid(EnemyTank))
		return;

	//�ӵ���ײ�����壬��������˺�
	TObject *object = dynamic_cast<TObject *>(collisionTarget);
	object->DamageHealth(m_power);
	DamageHealth(100);
}