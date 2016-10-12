#pragma once
#include "Global.h"
#include <list>

class IRigid;
class ManagerGroup;

class CollisionManager
{
private:
	//����������
	ManagerGroup *m_managerGroup;
	//��������
	std::list<IRigid*> m_rigidList;

public:
	//���캯��
	CollisionManager(ManagerGroup *managerGroup);

	//��ײ���
	void CollisionDectect(IRigid *rigid);
	//�������
	bool DeadDectect(IRigid *rigid);
	//ע�����
	void RegisterRigid(IRigid *rigid);
	//ɾ������
	void DeleteRigid(IRigid *rigid);
	//�Ƿ�ռ��
	bool IsOccupied(IRigid *rigid);
};