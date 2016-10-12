#pragma once
#include "Global.h"
class GameWorld;

//******TObject.h
//******�ļ�����:	Tobject��̹��������Ϸ�����еĶ���Ļ���
//******����:		�����
//******�������:	2015��10��28��12:20:16

class TObject
{
protected:
	Vector2D m_position ;		//2D����
	int m_health ;				//����ֵ
	int m_defense ;				//����ֵ
	bool m_isDead ;				//�Ƿ��Ѿ�����
	//ÿһ��������һ����������Ϸ���磿��������
	GameWorld *m_gameWorld;		//��������Ϸ����

public:
	TObject(Vector2D &position, int health, int defense, GameWorld *gameWorld);

public:
	void setPosition(int x, int y);
	void setPosition(Vector2D &newPosition);

	Vector2D getPosition(void) ;
	int getHealth(void) ;
	int getDefense(void) ;
	bool isDead(void) ;

	virtual void AddHealth(int value) ;
	virtual void DamageHealth(int value) ;
	virtual void AddDefense(int value) ;
	virtual void DamageDefense(int value) ;
	virtual void Resurrect(void);
};
