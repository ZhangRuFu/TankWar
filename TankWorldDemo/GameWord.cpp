//GameWorld��ʵ���ļ�
#include "GameWorld.h"
#include "MapManager.h"
#include "SoulManager.h"
#include "ResourceManager.h"
#include "CollisionManager.h"
#include "EffectManager.h"
#include "ManagerGroup.h"
#include "PlayerTank.h"
#include "EnemyTank.h"
#include "Bullet.h"
#include "View.h"
#include "Controller.h"
#include <typeinfo>

GameWorld::GameWorld(int delayTime)
{
	m_managerGroup = nullptr;
	m_delayTime = delayTime;
}

//��ȡ��Ϸ״̬
GameState GameWorld::getGameState(void)
{
	return m_gameState ;
}

PlayerTank * GameWorld::GetPlayerTank(void)
{
	return m_managerGroup->GetSoulManager()->getPlayerTank();
}

int GameWorld::getDelayTime(void)
{
	return m_delayTime;
}

void GameWorld::AddSoul(TSoul * soul)
{
	m_managerGroup->AddSoul(soul);
}

//��Ϸ��ʼ
void GameWorld::GameStart(void)
{
	m_gameState = GameState::Gaming ;
}

//��Ϸ��ͣ
void GameWorld::GamePause(void)
{
	m_gameState = GameState::Pause ;
}

//��Ϸ����
void GameWorld::GameOver(void)
{
	m_gameState = GameState::Over ;
}

//��Ϸ��ʼ��
void GameWorld::GameInit(HWND hwnd)
{
	m_gameState = GameState::PreGame ;

	m_managerGroup = new ManagerGroup(this, hwnd);

	m_managerGroup->GetMapManager()->RegisterBarrier() ;
	m_managerGroup->GetSoulManager()->RegisterSoul() ;
}

void GameWorld::MoveAll(void) 
{
	if (m_gameState == GameState::Gaming)
		m_managerGroup->MoveAll();
}

void GameWorld::DrawAll(void)
{
	if (m_gameState == GameState::Gaming)
	{
		m_managerGroup->DrawAll();
	}
	else if (m_gameState == GameState::PreGame)
	{
		m_managerGroup->DrawPreGame();
	}
	else if (m_gameState == GameState::Over)
	{
		m_managerGroup->DrawGameOver();
	}
}

void GameWorld::CollisionDectect(IRigid * rigid)
{
	m_managerGroup->CollisionDectect(rigid);
}

void GameWorld::KeyMessage(WPARAM keyCode)
{
	m_managerGroup->KeyMessage(keyCode);
}
