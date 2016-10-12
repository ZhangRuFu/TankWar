#pragma once
#include "Global.h"
#include "Tank.h"

class EnemyTank : public Tank
{
private:
	//�о�̹������
	//��ʹ�ü̳���������ͬ�ĵо�̹�ˣ�����ʹ�����ͻ����ʲô��
	//��ͬ��̹��ֻ�ǻ������Բ�ͬ����۲�ͬ���������������ͬ�������Ժ���չĳЩ̹�������Ͳ�����ը
	//�ŵ㣺���ټ̳���
	//ȱ�㣺��Ҫ����image��list��Ϊ���
	EnemyTankType m_type ;
	int m_delayTime;
	int m_lastTime;
public:
	//���ʺ���
	Image* getApperance(void);
public:
	EnemyTank(Vector2D& position, Direction& direction, EnemyTankType type, GameWorld *gameWorld);

	//ʵ�ָ���ӿں���
	virtual void CollisionEvent(IRigid *collisionTarget, Vector2D position);
	virtual void Move(void);

	virtual void Fire(void);
};