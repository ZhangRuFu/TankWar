#include <Windows.h>
#include <string>

#include "Global.h"
#include "Controller.h"
#include "GameWorld.h"
#include "View.h"

using namespace std;
using namespace Gdiplus;

GameWorld gameWorld(40);

void CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
void UpdateView(const HDC *hdc);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR cmdStr, int nCmdShow)
{
	WNDCLASS wndClass;
	wstring wndClassName(L"MainWndClass");
	wstring windowName(L"TankGame");
	GdiplusStartupInput gdiInput;
	ULONG_PTR gdiToken;
	
	srand(GetTickCount());//随机数种子
	
#pragma region InitGdiPlus
	Gdiplus::GdiplusStartup(&gdiToken, &gdiInput, NULL);
#pragma endregion

#pragma region Fill Wndclass And Register
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpszClassName = wndClassName.c_str();
	wndClass.lpszMenuName = NULL;
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, L"IDC_ARROW");
	wndClass.hIcon = LoadIcon(NULL, L"IDI_APPLICATION");

	if (!RegisterClass(&wndClass))
	{
		MessageBox(NULL, L"Register wndClass Failed!", L"Error", MB_OK);
		return 1;
	}
#pragma endregion

#pragma region CreateWindow
	RECT windowRect;
	SetRect(&windowRect, 0, 0, View::m_screenWidth + View::m_scoreWidth, View::m_screenHeight);
	AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, false);
	HWND hWnd;
	hWnd = CreateWindow(wndClassName.c_str(), windowName.c_str(), WS_OVERLAPPEDWINDOW, 50, 50, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
#pragma endregion

#pragma region Message Loop
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
#pragma endregion

	GdiplusShutdown(gdiToken);
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	PAINTSTRUCT ps;
	switch (message)
	{
	case WM_KEYDOWN:
		gameWorld.KeyMessage(wparam);
		break;
	case WM_CREATE:
		gameWorld.GameInit(hwnd);
		SetTimer(hwnd, 1000, gameWorld.getDelayTime(), TimerProc);
		break;
	case WM_ERASEBKGND:
		return true;
		break;
	case WM_PAINT:
		BeginPaint(hwnd, &ps);
		UpdateView(&ps.hdc);
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wparam, lparam);
	}
	return 0;
}

//重绘函数
void UpdateView(const HDC *hdc)
{
	gameWorld.DrawAll();
}

void CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
	gameWorld.MoveAll();
	InvalidateRect(hwnd, nullptr, true);
	UpdateWindow(hwnd);
}