#pragma once
#include <list>
#include "Global.h"

using namespace std;

class GameWorld;
class Barrier;
class IronBarrier;
class BrickBarrier;
class GrassBarrier;
class HomeBarrier;
class CollisionManager;
class ManagerGroup;
class View;

class MapManager
{
private:
	list<IronBarrier*> m_ironBarrier ;
	list<BrickBarrier*> m_brickBarrier ;
	list<GrassBarrier*> m_grassBarrier ;
	HomeBarrier *m_home;

private:
	ManagerGroup *m_managerGroup;

public:
	MapManager(ManagerGroup *managerGroup);

	//把障碍注册到list中
	void RegisterBarrier() ;
	//删除精灵
	void DeleteBarrier(Barrier *barrier);
	//删除刚体
	void DeleteRigid(IRigid * rigid);
	//绘制全部障碍
	void DrawAll(void) ;
};