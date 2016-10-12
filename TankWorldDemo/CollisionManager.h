#pragma once
#include "Global.h"
#include <list>

class IRigid;
class ManagerGroup;

class CollisionManager
{
private:
	//所属管理组
	ManagerGroup *m_managerGroup;
	//刚体链表
	std::list<IRigid*> m_rigidList;

public:
	//构造函数
	CollisionManager(ManagerGroup *managerGroup);

	//碰撞检测
	void CollisionDectect(IRigid *rigid);
	//死亡检测
	bool DeadDectect(IRigid *rigid);
	//注册刚体
	void RegisterRigid(IRigid *rigid);
	//删除刚体
	void DeleteRigid(IRigid *rigid);
	//是否被占据
	bool IsOccupied(IRigid *rigid);
};