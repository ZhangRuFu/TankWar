#pragma once
#include "TObject.h"
//������ϰ�����Ϊ��ƺ�ϰ��ﲻ���и��������
//���Բ�ͬ���ϰ����Barrier����
class Barrier : public TObject
{
private:

public:
	Barrier(Vector2D &position, int health, int defense, GameWorld* gameWorld);
};
