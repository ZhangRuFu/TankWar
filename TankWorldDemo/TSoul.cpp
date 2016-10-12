//TSoul��ʵ���ļ�
#include "TSoul.h"
#include "GameWorld.h"
//���캯��
TSoul::TSoul(Vector2D &position, int health, int defense, GameWorld *gameWorld, Direction direction, int speed) : TObject(position, health, defense, gameWorld)
{
	m_direction = direction ;
	m_speed = speed ;
}

//���ʺ���
Direction TSoul::getDirection(void)
{
	return m_direction ;
}

//��ȡ�ٶ�
int TSoul::getSpeed(void)
{
	return m_speed ;
}

//���÷���
void TSoul::setDirection(const Direction &direction)
{
	m_direction = direction;
}

//�����ٶ�
void TSoul::AddSpeed(int speed)
{
	if(speed <= 0)
		return ;
	m_speed += speed ;
	return ;
}

//�����ٶ�
void TSoul::ReduceSpeed(int speed)
{
	if(speed <= 0)
		return ;
	m_speed -= speed ;
	if (m_speed < 0)
		m_speed = 0;
	return ;
}