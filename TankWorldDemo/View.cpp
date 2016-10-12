#include "View.h"
#include "ResourceManager.h"
#include "EffectManager.h"
#include "TObject.h"
#include <typeinfo>

View::View(HWND hwnd)
{
	m_hwnd = hwnd;
	m_screenBitmap = new Bitmap(m_screenWidth, m_screenHeight);
	m_scoreBitmap = new Bitmap(m_scoreWidth, m_scoreHeight);
	m_fullBitmap = new Bitmap(m_fullWidth, m_fullHeight);

	m_screenGraphic = Graphics::FromImage(m_screenBitmap);
	m_scoreGraphic = Graphics::FromImage(m_scoreBitmap);
	m_fullGraphic = Graphics::FromImage(m_fullBitmap);

	m_resourceManager = ResourceManager::GetInstance();
}

void View::DrawImage(Gdiplus::Image * image, Vector2D & position, int apperanceWidth, int apperanceHeight)
{
	int rightX = position.getX() - apperanceWidth / 2;
	int rightY = position.getY() - apperanceHeight / 2;
	m_screenGraphic->DrawImage(image, rightX, rightY, apperanceWidth, apperanceHeight);	
}

void View::DrawScoreBoard(int restCount)
{
	int marginLeft = 15;
	int marginUp = 20;
	int x = 0;
	int y = 0;
	for (int i = 0;i < restCount; i++)
	{
		x = marginLeft + (i % 2) * 40;
		y = marginUp + (i / 2) * 50;
		//»­·ÖÊý°æ
		m_scoreGraphic->DrawImage(m_resourceManager->GetScoreElementImage(0), x, y, 30, 30);
		//»­ÆìÖÄ
		m_scoreGraphic->DrawImage(m_resourceManager->GetScoreElementImage(1), 20, 400, 40, 40);
	}
}

void View::GameOver(void)
{
	m_screenGraphic->DrawImage(m_resourceManager->GetGameStateElementImage(1), 100, 200);
}

void View::GameReady(void)
{
	m_fullGraphic->Clear(Color(255, 255, 255));
	m_fullGraphic->DrawImage(m_resourceManager->GetGameStateElementImage(0), 0, 0, View::m_fullWidth, View::m_fullHeight);
	HDC hdc = GetDC(m_hwnd);
	Graphics graphic(hdc);
	graphic.DrawImage(m_fullBitmap, 0, 0);
	ReleaseDC(m_hwnd, hdc);
}

void View::DrawInit(void)
{
	m_screenGraphic->Clear(Color(0, 0, 0));
	m_scoreGraphic->Clear(Color(90, 90, 90));
}

void View::DrawFinish(void)
{
	HDC hdc = GetDC(m_hwnd);
	Graphics graphic(hdc);
	graphic.DrawImage(m_screenBitmap, 0, 0);
	graphic.DrawImage(m_scoreBitmap, 600, 0);
	ReleaseDC(m_hwnd, hdc);
}

void View::DrawGameElement(TObject *object)
{
	Image *image = m_resourceManager->GetGameElementImage(object);
	Vector2D &position = object->getPosition();
	int x = position.getX() - image->GetWidth() / 2;
	int y = position.getY() - image->GetHeight() / 2;
	m_screenGraphic->DrawImage(image, x, y);
}

void View::DrawEffectElement(Effect *effect)
{
	Image *image = m_resourceManager->GetEffectElementImage(effect);
	Vector2D &position = effect->getPosition();
	int x = position.getX() - image->GetWidth() / 2;
	int y = position.getY() - image->GetHeight() / 2;
	m_screenGraphic->DrawImage(image, x, y);
}

View* View::GetInstance(HWND hwnd)
{
	if (nullptr == View::m_view)
		m_view = new View(hwnd);
	return m_view;
}

View *View::m_view = nullptr;