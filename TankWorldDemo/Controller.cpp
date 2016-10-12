#include "Controller.h"
#include "PlayerTank.h"
#include "GameWorld.h"
#include "ManagerGroup.h"

Controller::Controller(ManagerGroup *managerGroup)
{
	m_managerGroup = managerGroup;
}

Controller* Controller::GetInstance(ManagerGroup *managerGroup)
{
	if(Controller::m_controller == nullptr)
		Controller::m_controller = new Controller(managerGroup);
	return Controller::m_controller;
}

void Controller::KeyboardMessage(WPARAM keyCode)
{
	static GameWorld *gameWorld = m_managerGroup->GetGameWorld();
	Direction direction = gameWorld->GetPlayerTank()->getDirection();
	bool isFire = false;
	//键盘事件处理
	switch (keyCode)
	{
	case VK_UP:
		direction = Direction::Up;
		break;
	case VK_DOWN:
		direction = Direction::Down;
		break;
	case VK_LEFT:
		direction = Direction::Left;
		break;
	case VK_RIGHT:
		direction = Direction::Right;
		break;
	case VK_SPACE:
		isFire = true;
		break;
	case VK_ESCAPE:
		if (gameWorld->getGameState() == GameState::PreGame)
			PostQuitMessage(0);
		return;
	case VK_RETURN:
		if(gameWorld->getGameState() == GameState::PreGame)
			gameWorld->GameStart();
		return;
	default:
		return;
	}
	if (isFire)
	{
		gameWorld->GetPlayerTank()->Fire();
		return;
	}
	gameWorld->GetPlayerTank()->Drive(direction);
	return;
}

Controller *Controller::m_controller = nullptr;