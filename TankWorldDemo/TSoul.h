#pragma once
#include "TObject.h"

//******TObject.h
//******�ļ�����:	TSoul���������壬�̳���TObject
//******����:		�����
//******�������:	2015��10��28��12:20:16
class TSoul : public TObject
{
protected:
	Direction m_direction ;		//����
	int m_speed ;				//�ٶ�
	

public:
	TSoul(Vector2D &position, int health, int defense, GameWorld *gameWorld, Direction direction, int speed);
	Direction getDirection(void);
	int getSpeed(void) ;
	void setDirection(const Direction &direction) ;
	
	void AddSpeed(int value) ;
	void ReduceSpeed(int value) ;

	virtual void Move(void) = 0;
};

	