#pragma once
#include "Global.h"
#include <vector>
#include <list>

class View;
class ManagerGroup;

using namespace std;

class Effect
{
protected:
	Vector2D m_position;
	int m_currentFrame;
	bool m_isDead;

public:
	Effect(Vector2D position);
	bool IsDead(void);
	int getCurrentFrame(void);
	Vector2D getPosition(void);

	virtual void Move(void) = 0;
};

//爆炸效果
class Bomb : public Effect
{
private:
	BombStyle m_bombStyle;

private:
	static int m_bigFrame;
	static int m_smallFrame;

public:
	Bomb(Vector2D bombPosition, BombStyle style);
	virtual void Move(void);
};

//出生特效
class Birth : public Effect
{
private:
	int m_loop;

private:
	static int m_maxFrame;
	
public:
	Birth(Vector2D birthPosition);
	virtual void Move(void);
};


//特效管理器
class EffectManager
{
private:
	list<Bomb*> m_bombList;
	list<Birth*> m_birthList;
	
private:
	ManagerGroup *m_managerGroup;

public:
	EffectManager(ManagerGroup *managerGroup);
	
	void AddBomb(Vector2D bombPosition, BombStyle style = BombStyle::BigBomb);
	void AddBirth(Vector2D birthPosition);
	void DrawEffect(void);
	void Move(void);
};