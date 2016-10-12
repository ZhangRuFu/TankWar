#pragma once
#include "Global.h"

class View;
class SoulManager;
class ResourceManager;
class EffectManager;
class MapManager;
class CollisionManager;
class GameWorld;
class Controller;
class IRigid;
class PlayerTank;
class TSoul;

class ManagerGroup
{
private:
	GameWorld *m_gameWorld;
	View *m_view;
	Controller *m_controller;
	SoulManager *m_soulManager;
	MapManager *m_mapManager;
	CollisionManager *m_collisionManager;
	EffectManager *m_effectManager;

public:
	ManagerGroup(GameWorld *gameWorld, HWND hwnd);

	GameWorld *GetGameWorld(void);
	View* GetView(void);
	SoulManager* GetSoulManager(void);
	MapManager* GetMapManager(void);
	CollisionManager* GetCollisionManager(void);
	EffectManager* GetEffectManager(void);

	void DrawAll(void);
	void DrawPreGame(void);
	void DrawGameOver(void);
	void MoveAll(void);

	//管理员任务
	void CollisionDectect(IRigid *rigid);
	void KeyMessage(WPARAM keyCode);
	PlayerTank* GetPlayerTank(void);
	void AddSoul(TSoul *soul);

};