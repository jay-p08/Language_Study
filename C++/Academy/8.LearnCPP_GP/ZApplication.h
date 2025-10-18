#pragma once

// 게임 윈도우

class ZApplication
{
public:
	class Exception : public ChiliException
	{
		using ChiliException::ChiliException;
	public:
		static std::string TranslateErrorCode(HRESULT hr) noexcept;
	};
	class HrException : public Exception
	{
	public:
		HrException(int line, const char* file, HRESULT hr) noexcept;
		const char* what() const noexcept override;
		const char* GetType() const noexcept override;
		HRESULT GetErrorCode() const noexcept;
		std::string GetErrorDescription() const noexcept;
	private:
		HRESULT hr;
	};
	class NoGfxException : public Exception
	{
	public:
		using Exception::Exception;
		const char* GetType() const noexcept override;
	};

private:
	HINSTANCE	m_hInst;
	HWND		m_hWnd;

protected:
	TCHAR		m_Class[MAX_PATH];
	TCHAR		m_Caption[MAX_PATH];

	WNDCLASSEX	m_wcex;

	DWORD		m_Style;
	DWORD		m_XPos;
	DWORD		m_YPos;
	DWORD		m_Width;
	DWORD		m_Height;
    DWORD       m_ClientWidth;
    DWORD       m_ClientHeight;

public:
	ZApplication(DWORD XPos = 0, DWORD YPos = 0, DWORD Width = 640, DWORD Height = 480, DWORD ClientWidth = 640, DWORD ClientHeight = 480);

	HWND		GetHWnd();
	HINSTANCE	GetHInst();

	BOOL Run();
	BOOL Error(BOOL Fatal, const TCHAR* Text, ...);

	BOOL Move(long XPos, long YPos);
	BOOL Resize(long Width, long Height);

	BOOL ShowMouse(BOOL Show = TRUE);

	virtual LRESULT CALLBACK MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) 
	{ 
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	virtual BOOL Init() { return TRUE; }
	virtual BOOL Shutdown() { return TRUE; }
	virtual BOOL Frame() { return TRUE; }
};

static ZApplication* g_pApplication = NULL;
static LRESULT CALLBACK AppWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
