//TSoul的实现文件
#include "TSoul.h"
#include "GameWorld.h"
//构造函数
TSoul::TSoul(Vector2D &position, int health, int defense, GameWorld *gameWorld, Direction direction, int speed) : TObject(position, health, defense, gameWorld)
{
	m_direction = direction ;
	m_speed = speed ;
}

//访问函数
Direction TSoul::getDirection(void)
{
	return m_direction ;
}

//获取速度
int TSoul::getSpeed(void)
{
	return m_speed ;
}

//设置方向
void TSoul::setDirection(const Direction &direction)
{
	m_direction = direction;
}

//增加速度
void TSoul::AddSpeed(int speed)
{
	if(speed <= 0)
		return ;
	m_speed += speed ;
	return ;
}

//降低速度
void TSoul::ReduceSpeed(int speed)
{
	if(speed <= 0)
		return ;
	m_speed -= speed ;
	if (m_speed < 0)
		m_speed = 0;
	return ;
}