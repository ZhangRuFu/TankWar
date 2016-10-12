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

//����ö��
enum Direction {Up, Down, Left, Right} ;

//�о�̹������ö��
enum EnemyTankType{Normal, Hard} ;

//�ӵ�����ö��
enum BulletType{Small, Big} ;

//�ӵ�������
enum BulletOwner{Player, Enemy};

//��Ϸ״̬ö��
enum GameState{PreGame, Over, Gaming, Pause} ;

//��ը����
enum BombStyle { BigBomb, SmallBomb };