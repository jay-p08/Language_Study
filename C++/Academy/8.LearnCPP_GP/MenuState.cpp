#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include "MenuState.h"
#include "PlayState.h"
#include "CPPGP2025.h"
#include "Bitmap.h"

#pragma comment(lib, "winmm.lib")

extern void ChangeState(GameState* newState);

BmpImage g_bmpMenu;

void MenuState::Enter(HWND hWnd)
{
	std::cout << "Enter MenuState" << std::endl;
	if (!g_bmpMenu.Load(L"GameOver.bmp")) {
		MessageBox(hWnd, L"BMP 파일 로드 실패!", L"Error", MB_ICONERROR);
	}
}

void MenuState::Exit()
{
	std::cout << "Exit MenuState" << std::endl;
}

void MenuState::Update(float elapsedTime)
{

}

void MenuState::Render(HDC hdc)
{
	g_bmpMenu.Draw(hdc, 10, 10);
	/*
	RECT rect;
	GetClientRect(GetActiveWindow(), &rect);
	const TCHAR* text = L"Title Screen - Press Enter to Start";
	DrawText(hdc, text, -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	*/
}

void MenuState::OnKeyDown(WPARAM wParam)
{
	if (wParam == VK_RETURN)
	{
		std::cout << "Goto PlayState" << std::endl;
		ChangeState(new PlayState());
	}
}

void MenuState::OnKeyUp(WPARAM wParam)
{

}

void MenuState::OnMouseDown(int x, int y, int button)
{

}

void MenuState::OnMouseUp(int x, int y, int button)
{

}

void MenuState::OnMouseMove(int x, int y)
{

}