#include "ManagerGroup.h"
#include "GameWorld.h"
#include "Controller.h"
#include "View.h"
#include "MapManager.h"
#include "SoulManager.h"
#include "ResourceManager.h"
#include "CollisionManager.h"
#include "EffectManager.h"
#include "PlayerTank.h"

ManagerGroup::ManagerGroup(GameWorld *gameWorld, HWND hwnd)
{
	m_gameWorld = gameWorld;
	m_controller = Controller::GetInstance(this);
	m_view = View::GetInstance(hwnd);
	m_collisionManager = new CollisionManager(this);
	m_effectManager = new EffectManager(this);
	m_mapManager = new MapManager(this);
	m_soulManager = new SoulManager(this);
}

GameWorld * ManagerGroup::GetGameWorld(void)
{
	return m_gameWorld;
}

View * ManagerGroup::GetView(void)
{
	return m_view;
}

SoulManager * ManagerGroup::GetSoulManager(void)
{
	return m_soulManager;
}

MapManager * ManagerGroup::GetMapManager(void)
{
	return m_mapManager;
}

CollisionManager * ManagerGroup::GetCollisionManager(void)
{
	return m_collisionManager;
}

EffectManager * ManagerGroup::GetEffectManager(void)
{
	return m_effectManager;
}

void ManagerGroup::MoveAll(void)
{
	m_soulManager->MoveAll();
	m_effectManager->Move();
}

void ManagerGroup::DrawAll(void)
{
	m_view->DrawInit();
	m_soulManager->DrawAll();
	m_mapManager->DrawAll();
	m_effectManager->DrawEffect();
	m_view->DrawScoreBoard(m_soulManager->getRestCount());
	m_view->DrawFinish();
}

void ManagerGroup::DrawPreGame(void)
{
	m_view->GameReady();
	
}

void ManagerGroup::DrawGameOver(void)
{
	m_view->GameOver();
	m_view->DrawFinish();
}

void ManagerGroup::CollisionDectect(IRigid * rigid)
{
	m_collisionManager->CollisionDectect(rigid);
}

void ManagerGroup::KeyMessage(WPARAM keyCode)
{
	m_controller->KeyboardMessage(keyCode);
}

PlayerTank * ManagerGroup::GetPlayerTank(void)
{
	return m_soulManager->getPlayerTank();
}

void ManagerGroup::AddSoul(TSoul * soul)
{
	m_soulManager->RegisterSoul(soul);
}
