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
	//��Ϸ���ʱ��
	int m_delayTime;
	//��Ϸ״̬
	enum GameState m_gameState ;
	ManagerGroup *m_managerGroup;

public:
	//���캯��
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