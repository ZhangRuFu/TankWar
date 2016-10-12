#pragma once
#include <comdef.h>
#include <gdiplus.h>
using namespace Gdiplus;

#pragma comment(lib, "Gdiplus.lib")

class Vector2D
{
private:
	int m_x ;
	int m_y ;
public:
	Vector2D(int x, int y) ;
	
	int getX(void) { return m_x; };
	int getY(void) { return m_y; };
	void setX(int x) { m_x = x; };
	void setY(int y) { m_y = y; };

	void AddX(int delta);
	void AddY(int delta);
	void ReduceX(int delta);
	void ReduceY(int delta);

	bool operator==(Vector2D &another);
};

class iRect
{
public:
	int m_x;
	int m_y;
	int m_width;
	int m_height;

public:
	iRect(int x, int y, int width, int height);
	operator RECT(void);
};

//方向枚举
enum Direction {Up, Down, Left, Right} ;

//敌军坦克类型枚举
enum EnemyTankType{Normal, Hard} ;

//子弹类型枚举
enum BulletType{Small, Big} ;

//子弹归属者
enum BulletOwner{Player, Enemy};

//游戏状态枚举
enum GameState{PreGame, Over, Gaming, Pause} ;

//爆炸类型
enum BombStyle { BigBomb, SmallBomb };