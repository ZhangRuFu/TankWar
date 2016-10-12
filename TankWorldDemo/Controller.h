#pragma once
#include <Windows.h>
#include "Global.h"

class PlayerTank;
class ManagerGroup;

class Controller
{
private:
	ManagerGroup *m_managerGroup;

	static Controller* m_controller;
private:
	Controller(ManagerGroup *managerGroup) ;

public:
	static Controller* GetInstance(ManagerGroup *managerGroup);
	void KeyboardMessage(WPARAM keyCode);
};