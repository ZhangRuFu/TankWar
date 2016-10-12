#include "ResourceManager.h"
#include "EffectManager.h"
#include "View.h"
#include "typeinfo"
#include "PlayerTank.h"
#include "EnemyTank.h"
#include "Bullet.h"
#include "IronBarrier.h"
#include "BrickBarrier.h"
#include "GrassBarrier.h"
#include "HomeBarrier.h"

//������Ϸ��Դ
ResourceManager::ResourceManager(void)
{
	//�о�̹����ͼ
	m_enemyTankImage.push_back(Image::FromFile(L"TankResource\\enemy1U.gif"));
	m_enemyTankImage.push_back(Image::FromFile(L"TankResource\\enemy1D.gif"));
	m_enemyTankImage.push_back(Image::FromFile(L"TankResource\\enemy1L.gif"));
	m_enemyTankImage.push_back(Image::FromFile(L"TankResource\\enemy1R.gif"));

	//���̹����ͼ
	m_playerTankImage.push_back(Image::FromFile(L"TankResource\\p1tankU.gif"));
	m_playerTankImage.push_back(Image::FromFile(L"TankResource\\p1tankD.gif"));
	m_playerTankImage.push_back(Image::FromFile(L"TankResource\\p1tankL.gif"));
	m_playerTankImage.push_back(Image::FromFile(L"TankResource\\p1tankR.gif"));

	//�ӵ���ͼ
	m_bulletImage.push_back(Image::FromFile(L"TankResource\\bullet.png"));

	//������ͼ
	m_ironBarrier.push_back(Image::FromFile(L"TankResource\\steels.gif"));
	//ש����ͼ
	m_brickBarrier.push_back(Image::FromFile(L"TankResource\\walls.gif"));
	//�ݴ���ͼ
	m_grassBarrier.push_back(Image::FromFile(L"TankResource\\grass.gif"));
	//������ͼ
	m_home.push_back(Image::FromFile(L"TankResource\\symbol.gif"));
	m_home.push_back(Image::FromFile(L"TankResource\\destory.gif"));

	//��ը��Ч��ͼ
	m_bombImage.push_back(Image::FromFile(L"TankResource\\blast1.gif"));
	m_bombImage.push_back(Image::FromFile(L"TankResource\\blast2.gif"));
	m_bombImage.push_back(Image::FromFile(L"TankResource\\blast3.gif"));
	m_bombImage.push_back(Image::FromFile(L"TankResource\\blast4.gif"));
	m_bombImage.push_back(Image::FromFile(L"TankResource\\blast5.gif"));
	m_bombImage.push_back(Image::FromFile(L"TankResource\\blast6.gif"));
	m_bombImage.push_back(Image::FromFile(L"TankResource\\blast7.gif"));
	m_bombImage.push_back(Image::FromFile(L"TankResource\\blast8.gif"));

	//������Ч��ͼ
	m_birthImage.push_back(Image::FromFile(L"TankResource\\born1.gif"));
	m_birthImage.push_back(Image::FromFile(L"TankResource\\born2.gif"));
	m_birthImage.push_back(Image::FromFile(L"TankResource\\born3.gif"));
	m_birthImage.push_back(Image::FromFile(L"TankResource\\born4.gif"));
	m_birthImage.push_back(Image::FromFile(L"TankResource\\born5.gif"));
	m_birthImage.push_back(Image::FromFile(L"TankResource\\born6.gif"));
	m_birthImage.push_back(Image::FromFile(L"TankResource\\born7.gif"));
	

	//������ͼ
	m_scoreElement.push_back(Image::FromFile(L"TankResource\\score.png"));
	m_scoreElement.push_back(Image::FromFile(L"TankResource\\flag.png"));

	//��Ϸ״̬��ͼ
	m_gameStateElement.push_back(Image::FromFile(L"TankResource\\gameready.png"));
	m_gameStateElement.push_back(Image::FromFile(L"TankResource\\failed.png"));
}

//��ȡ��ϷԪ����Դ
Image* ResourceManager::GetGameElementImage(TObject * object)
{
	//�ж�TObject������ͼ
	Image *image = nullptr;
	const std::type_info &info = typeid(*object);

	if (info == typeid(PlayerTank))
		//���̹����Դ
		image = m_playerTankImage[((PlayerTank *)object)->getDirection()];
	else if (info == typeid(EnemyTank))
		//�о�̹����Դ
		image = m_enemyTankImage[((EnemyTank *)object)->getDirection()];
	else if (info == typeid(Bullet))
		//�ӵ���Դ
		image = m_bulletImage[0];
	else if (info == typeid(IronBarrier))
		//������Դ
		image = m_ironBarrier[0];
	else if (info == typeid(BrickBarrier))
		//ש����Դ
		image = m_brickBarrier[0];
	else if (info == typeid(GrassBarrier))
		//�ݴ���Դ
		image = m_grassBarrier[0];
	else if(info == typeid(HomeBarrier))
		//������Դ
		image = m_home[object->isDead() ? 1 : 0];
	return image;
}

Image* ResourceManager::GetEffectElementImage(Effect *effect)
{
	Image *image = nullptr;
	const type_info &info = typeid(*effect);
	if (info == typeid(Bomb))
		image = m_bombImage[effect->getCurrentFrame()];
	else if (info == typeid(Birth))
		image = m_birthImage[effect->getCurrentFrame()];
	return image;
}

Image * ResourceManager::GetScoreElementImage(int index)
{
	return m_scoreElement[index];
}

Image * ResourceManager::GetGameStateElementImage(int index)
{
	return m_gameStateElement[index];
}

ResourceManager * ResourceManager::GetInstance(void)
{
	if (nullptr == m_resourceManager)
		m_resourceManager = new ResourceManager();
	return m_resourceManager;
}

ResourceManager* ResourceManager::m_resourceManager = nullptr;