#pragma once
#include "TSoul.h"
#include "IRigid.h"
#include <vector>
using namespace std;
//******Tank.h
//******�ļ�����:	����Tank��Ļ���
//******����:		�����
//******�������:	2016��5��8��22:41:50
class Tank : public TSoul, public IRigid
{
protected:
	enum BehavoirState { Stop, Action };

protected:
	BehavoirState m_behavoirState;
	Vector2D m_oldPosition;

public:
	Tank(Vector2D &position, int health, int defense, int apperanceWidth, int apperanceHeight, Direction direction, int speed, GameWorld *gameWorld);
	virtual iRect GetRigidBody(void);

	virtual void Fire(void) = 0;
	virtual void Move(void);
};