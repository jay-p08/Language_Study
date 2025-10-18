#pragma once

// 게임 윈도우 생성/관리

class ZApp : public ZApplication
{
private:
	ZGraphics* m_pGraphics;

public:
	virtual LRESULT CALLBACK MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	ZApp(const TCHAR* pszCaption, DWORD XPos = 0, DWORD YPos = 0, DWORD Width = 640, DWORD Height = 480, DWORD ClientWidth = 640, DWORD ClientHeight = 640);
	virtual ~ZApp();

	DWORD GetWidth();
	DWORD GetHeight();
    DWORD GetClientWidth();
    DWORD GetClientHeight();

	BOOL Shutdown();
	BOOL Init();
	BOOL Frame();
};