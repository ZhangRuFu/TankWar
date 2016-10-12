#pragma once
#include "Tank.h"
#include <vector>
using namespace std;
//******Tank.h
//******文件描述:	玩家坦克类
//******作者:		张儒夫
//******完成世界:	2016年5月8日22:51:49
class PlayerTank : public Tank
{
private:
	int m_life ;	//命数
	
public:
	PlayerTank(int life, GameWorld* gameWorld) ;

public:
	bool hasLife(void);
	void Drive(Direction direction);
	
	//实现刚体接口函数
	virtual void CollisionEvent(IRigid *collisionTarget, Vector2D position);

	virtual void Fire(void);
	virtual void DamageHealth(int value);
};