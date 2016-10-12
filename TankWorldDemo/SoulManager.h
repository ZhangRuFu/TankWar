#pragma once
#include "Global.h"
#include <list>
#include <queue>

using namespace std;

class Bullet;
class PlayerTank;
class EnemyTank;
class GameWorld;
class TSoul;
class CollisionManager;
class EffectManager;
class View;
class IRigid;
class ManagerGroup;


class SoulManager
{
private:
	list<EnemyTank*> m_aliveEnemyTank ;
	list<EnemyTank*> m_birthEnemyTank ;
	PlayerTank *m_playerTank ;
	list<Bullet*> m_bullet ;
	//������
	Vector2D m_enemyBirthPoint[2];
	
	ManagerGroup *m_managerGroup;

	int m_restCount;

	//�о�̹��list����Ϊ5
	static const int m_maxAliveTank = 5 ;

public:
	SoulManager(ManagerGroup *managerGroup);

	PlayerTank* getPlayerTank(void);
	int getRestCount(void);

	//���ļ��ж�ȡ����
	void RegisterSoul() ;
	//��Ϸ�ж�̬�����ľ���
	void RegisterSoul(TSoul *soul);
	//ɾ������
	void AddEnemyTank(void);
	//��ӵ����������
	void RegisterRigid(IRigid *rigid);
	//ɾ������
	void DeleteRigid(IRigid *rigid);
	//��Ч����
	void EffectFinish(void);


	void MoveAll(void) ;
	void DrawAll(void) ;
};