#pragma once
#include "TObject.h"

//******TObject.h
//******文件描述:	TSoul代表活动的物体，继承自TObject
//******作者:		张儒夫
//******完成世界:	2015年10月28日12:20:16
class TSoul : public TObject
{
protected:
	Direction m_direction ;		//方向
	int m_speed ;				//速度
	

public:
	TSoul(Vector2D &position, int health, int defense, GameWorld *gameWorld, Direction direction, int speed);
	Direction getDirection(void);
	int getSpeed(void) ;
	void setDirection(const Direction &direction) ;
	
	void AddSpeed(int value) ;
	void ReduceSpeed(int value) ;

	virtual void Move(void) = 0;
};

	