#pragma once
#include "Global.h"
#include <list>
using namespace std;

class ManagerGroup;
class PlayerTank;
class TSoul;
class IRigid;
class EnnemyTank;
class Barrier;
class TObject;

class GameWorld
{
private:
	//游戏间隔时间
	int m_delayTime;
	//游戏状态
	enum GameState m_gameState ;
	ManagerGroup *m_managerGroup;

public:
	//构造函数
	GameWorld(int delayTime) ;

	GameState getGameState(void) ;
	PlayerTank* GetPlayerTank(void);
	int getDelayTime(void);


	void AddSoul(TSoul *soul);

	//Game State
	void GameInit(HWND hwnd);
	void GameStart(void) ;
	void GamePause(void) ;
	void GameOver(void) ;

	
	void MoveAll(void) ;
	void DrawAll(void) ;

	//Call Manager
	void CollisionDectect(IRigid *rigid);
	void KeyMessage(WPARAM keyCode);
};