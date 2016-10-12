#pragma once
#include <vector>
#include "Global.h"
using namespace std;

class TObject;
class Effect;

class ResourceManager
{
private:
	//实体贴图
	vector<Image*>m_bulletImage;
	vector<Image*>m_playerTankImage;
	vector<Image*>m_enemyTankImage;
	vector<Image*>m_ironBarrier;
	vector<Image*>m_brickBarrier;
	vector<Image*>m_grassBarrier;
	vector<Image*>m_home;
	vector<Image*>m_scoreElement;
	vector<Image*>m_gameStateElement;

	//特效贴图
	vector<Image*>m_bombImage;
	vector<Image*>m_birthImage;
private:
	static ResourceManager *m_resourceManager;

private:
	ResourceManager();

public:
	Image* GetGameElementImage(TObject *object);
	Image* GetEffectElementImage(Effect *effect);
	Image* GetScoreElementImage(int index);
	Image* GetGameStateElementImage(int index);

public:
	static ResourceManager* GetInstance(void);
};