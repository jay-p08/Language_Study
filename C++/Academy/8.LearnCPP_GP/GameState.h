#pragma once

class GameState
{
public:
	virtual ~GameState() {}

	virtual void Enter(HWND hWnd) = 0;
	virtual void Exit() = 0;
	virtual void Update(float elapsedTime) = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void OnKeyDown(WPARAM wParam) = 0;
	virtual void OnKeyUp(WPARAM wParam) = 0;
	virtual void OnMouseDown(int x, int y, int button) = 0;
	virtual void OnMouseUp(int x, int y, int button) = 0;
	virtual void OnMouseMove(int x, int y) = 0;
};