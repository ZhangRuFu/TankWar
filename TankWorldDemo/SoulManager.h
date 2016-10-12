#pragma once
#include "Global.h"
#include <list>
#include <queue>

using namespace std;

class Bullet;
class PlayerTank;
class EnemyTank;
class GameWorld;
class TSoul;
class CollisionManager;
class EffectManager;
class View;
class IRigid;
class ManagerGroup;


class SoulManager
{
private:
	list<EnemyTank*> m_aliveEnemyTank ;
	list<EnemyTank*> m_birthEnemyTank ;
	PlayerTank *m_playerTank ;
	list<Bullet*> m_bullet ;
	//出生点
	Vector2D m_enemyBirthPoint[2];
	
	ManagerGroup *m_managerGroup;

	int m_restCount;

	//敌军坦克list上限为5
	static const int m_maxAliveTank = 5 ;

public:
	SoulManager(ManagerGroup *managerGroup);

	PlayerTank* getPlayerTank(void);
	int getRestCount(void);

	//从文件中读取精灵
	void RegisterSoul() ;
	//游戏中动态产生的精灵
	void RegisterSoul(TSoul *soul);
	//删除精灵
	void AddEnemyTank(void);
	//添加到刚体管理器
	void RegisterRigid(IRigid *rigid);
	//删除刚体
	void DeleteRigid(IRigid *rigid);
	//特效结束
	void EffectFinish(void);


	void MoveAll(void) ;
	void DrawAll(void) ;
};