#pragma once
#include <Windows.h>
#include "Global.h"

class ResourceManager;
class Effect;
class Tank;
class Barrier;
class Bullet;
class TObject;
class Bomb;

class View
{
private:
	HWND m_hwnd;
	Bitmap *m_screenBitmap;
	Bitmap *m_scoreBitmap;
	Bitmap *m_fullBitmap;
	Graphics *m_screenGraphic;
	Graphics *m_scoreGraphic;
	Graphics *m_fullGraphic;

	ResourceManager *m_resourceManager;

public:
	static View *m_view;

	static const int m_screenWidth = 600;
	static const int m_screenHeight = 600;
	static const int m_scoreWidth = 100;
	static const int m_scoreHeight = m_screenHeight;
	static const int m_fullWidth = m_scoreWidth + m_screenWidth;
	static const int m_fullHeight = m_screenHeight;

public:
	View(HWND hwnd);

	void DrawInit(void);
	void DrawFinish(void);
	void DrawImage(Image *image, Vector2D &position, int apperanceWidth, int apperanceHeight);

	void DrawGameElement(TObject *object);
	void DrawEffectElement(Effect *effect);
	void DrawScoreBoard(int restCount);
	void GameOver(void);
	void GameReady(void);

public:
	static View* GetInstance(HWND hwnd);
};