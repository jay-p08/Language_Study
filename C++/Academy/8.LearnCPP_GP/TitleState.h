#pragma once
#include "GameState.h"

class TitleState : public GameState
{
public:
	void Enter(HWND hWnd) override;
	void Exit() override;
	void Update(float elapsedTime) override;
	void Render(HDC hdc) override;
	void OnKeyDown(WPARAM wParam) override;
	void OnKeyUp(WPARAM wParam) override;
	void OnMouseDown(int x, int y, int button) override;
	void OnMouseUp(int x, int y, int button) override;
	void OnMouseMove(int x, int y) override;
};