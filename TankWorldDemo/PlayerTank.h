#pragma once
#include "Tank.h"
#include <vector>
using namespace std;
//******Tank.h
//******�ļ�����:	���̹����
//******����:		�����
//******�������:	2016��5��8��22:51:49
class PlayerTank : public Tank
{
private:
	int m_life ;	//����
	
public:
	PlayerTank(int life, GameWorld* gameWorld) ;

public:
	bool hasLife(void);
	void Drive(Direction direction);
	
	//ʵ�ָ���ӿں���
	virtual void CollisionEvent(IRigid *collisionTarget, Vector2D position);

	virtual void Fire(void);
	virtual void DamageHealth(int value);
};