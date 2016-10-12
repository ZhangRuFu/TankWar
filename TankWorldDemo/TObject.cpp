//TObject的实现文件
#include "TObject.h"
#include "View.h"
#include "GameWorld.h"

TObject::TObject(Vector2D & position, int health, int defense, GameWorld *gameWorld) : m_position(position)
{
	m_health = health;
	m_defense = defense;
	m_isDead = false;
	m_gameWorld = gameWorld;
}

void TObject::setPosition(int x, int y)
{
	m_position.setX(x);
	m_position.setY(y) ;
}

void TObject::setPosition(Vector2D & newPosition)
{
	setPosition(newPosition.getX(), newPosition.getY());
}

Vector2D TObject::getPosition(void) { return m_position ; }

int TObject::getHealth(void) { return m_health ;}

int TObject::getDefense(void){return m_defense;}

bool TObject::isDead(void) { return m_isDead ; }

void TObject::AddHealth(int value)
{
	if(value <= 0)
		return ;
	m_health += value ;
	return ;
}

void TObject::DamageHealth(int value)
{
	if(value <= 0 || value <= m_defense)
		return ;
	m_health -= value - m_defense ;
	if(m_health <=0)
		m_isDead = true ;
	return ;
}

void TObject::AddDefense(int value)
{
	if(value <= 0)
		return ;
	m_defense += value ;
	return ;
}

void TObject::DamageDefense(int value)
{
	if(value <= 0)
		return ;
	m_defense -= value ;
	if(m_defense < 0)
		m_defense = 0 ;
	return ;
}

void TObject::Resurrect(void)
{
	m_isDead = false;
}