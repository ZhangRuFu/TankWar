#pragma once
#include "Global.h"
class GameWorld;

//******TObject.h
//******文件描述:	Tobject是坦克世界游戏中所有的对象的基类
//******作者:		张儒夫
//******完成世界:	2015年10月28日12:20:16

class TObject
{
protected:
	Vector2D m_position ;		//2D坐标
	int m_health ;				//生命值
	int m_defense ;				//防御值
	bool m_isDead ;				//是否已经消亡
	//每一个对象都有一个归属的游戏世界？？？？？
	GameWorld *m_gameWorld;		//归属的游戏世界

public:
	TObject(Vector2D &position, int health, int defense, GameWorld *gameWorld);

public:
	void setPosition(int x, int y);
	void setPosition(Vector2D &newPosition);

	Vector2D getPosition(void) ;
	int getHealth(void) ;
	int getDefense(void) ;
	bool isDead(void) ;

	virtual void AddHealth(int value) ;
	virtual void DamageHealth(int value) ;
	virtual void AddDefense(int value) ;
	virtual void DamageDefense(int value) ;
	virtual void Resurrect(void);
};
