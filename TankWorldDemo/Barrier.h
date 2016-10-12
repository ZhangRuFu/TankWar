#pragma once
#include "TObject.h"
//这里的障碍物因为草坪障碍物不具有刚体的特性
//所以不同的障碍物从Barrier派生
class Barrier : public TObject
{
private:

public:
	Barrier(Vector2D &position, int health, int defense, GameWorld* gameWorld);
};
