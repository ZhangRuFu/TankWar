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

	//���ϰ�ע�ᵽlist��
	void RegisterBarrier() ;
	//ɾ������
	void DeleteBarrier(Barrier *barrier);
	//ɾ������
	void DeleteRigid(IRigid * rigid);
	//����ȫ���ϰ�
	void DrawAll(void) ;
};