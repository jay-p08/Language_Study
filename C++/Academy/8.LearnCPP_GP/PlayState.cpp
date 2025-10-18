#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include "PlayState.h"
#include "MenuState.h"
#include "CPPGP2025.h"

#pragma comment(lib, "winmm.lib")

extern void ChangeState(GameState* newState);

void PlayState::Enter(HWND hWnd)
{
	std::cout << "Enter PlayState" << std::endl;
}

void PlayState::Exit()
{
	std::cout << "Exit PlayState" << std::endl;
}

void PlayState::Update(float elapsedTime)
{

}

void PlayState::Render(HDC hdc)
{
	/*
	RECT rect;
	GetClientRect(GetActiveWindow(), &rect);
	const TCHAR* text = L"Title Screen - Press Enter to Start";
	DrawText(hdc, text, -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	*/
}

void PlayState::OnKeyDown(WPARAM wParam)
{
	if (wParam == 'M')
	{
		std::cout << "Goto MenuState" << std::endl;
		ChangeState(new MenuState());
	}
}

void PlayState::OnKeyUp(WPARAM wParam)
{

}

void PlayState::OnMouseDown(int x, int y, int button)
{

}

void PlayState::OnMouseUp(int x, int y, int button)
{

}

void PlayState::OnMouseMove(int x, int y)
{

}
