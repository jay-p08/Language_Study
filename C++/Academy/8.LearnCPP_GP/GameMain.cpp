#include "GameGlobal.h"
#include <mmsystem.h> // timeGetTime()
#pragma comment(lib, "winmm.lib")

// 콘솔 창을 설정하는 함수
void SetupConsole()
{
    AllocConsole(); // 현재 프로세스에 새로운 콘솔 창을 할당합니다.
    FILE* pConsole;
    // freopen_s: 표준 스트림을 다른 파일이나 장치로 안전하게 리디렉션하는 함수입니다.
    // &pConsole: [out] 새로 열린 파일 스트림을 가리킬 포인터 변수의 주소입니다.
    // "CONOUT$": [in] 리디렉션할 대상 장치입니다. "CONOUT$"은 윈도우에서 '콘솔 출력 장치'를 의미하는 특수 파일 이름입니다.
    // "w": [in] 쓰기(write) 모드로 엽니다.
    // stdout: [in] 리디렉션할 표준 스트림입니다. 여기서는 '표준 출력'을 의미합니다.
    // 이 함수가 실행되면, 이후 stdout(그리고 이를 사용하는 std::cout)에 쓰는 모든 내용이 새로 할당된 콘솔 창에 출력됩니다.
    freopen_s(&pConsole, "CONOUT$", "w", stdout);
    // [핵심 설명: 왜 로컬 변수 pConsole이 사라져도 괜찮은가?]
    // 1. stdout 이란? : 프로그램 전체에서 유효한 '전역 파일 스트림'으로, '표준 출력'의 대상을 관리합니다.
    // 2. freopen_s의 역할: 이 함수는 '전역' stdout 객체의 내부 상태를 직접 수정하여, 출력이 영구적으로 새 콘솔을 향하도록 만듭니다.
    //    따라서 함수 내의 로컬 변수 pConsole은 임시 정보를 받는 역할일 뿐이며, 함수 종료 후 사라져도 stdout에 적용된 변경은 계속 유지됩니다.    
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    // 콘솔 설정
    SetupConsole();
    std::cout << "Console window is ready for logging!" << std::endl;

	// 클라이언트 영역 크기
	const int clientWidth = 1024;
	const int clientHeight = 600;

	RECT windowRect = { 0, 0, clientWidth, clientHeight };
	AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

	int windowWidth = windowRect.right - windowRect.left;
	int windowHeight = windowRect.bottom - windowRect.top;

	std::cout << "windowRect: " << windowWidth << " " << windowHeight << std::endl;

	// 화면 중앙 위치 계산
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	int x = (screenWidth - windowWidth) / 2;
	int y = (screenHeight - windowHeight) / 2;

	ZApp Game(_T("My D3D Test"), x, y, windowWidth, windowHeight, clientWidth, clientHeight);
	BOOL result = Game.Run();
	
	// 프로그램 종료 전 콘솔 해제
	FreeConsole();

	return result;
}

//------------------------------------------------------------------------------

ZApp::ZApp(const TCHAR* pszCaption,
	DWORD XPos, DWORD YPos, DWORD Width, DWORD Height, DWORD ClientWidth, DWORD ClientHeight)
	: ZApplication(XPos, YPos, Width, Height, ClientWidth, ClientHeight)
{
	m_pGraphics = nullptr;
	_tcscpy_s(m_Caption, pszCaption);
}

ZApp::~ZApp()
{
	SAFE_DELETE(m_pGraphics);
}

DWORD ZApp::GetWidth()
{
	return m_Width;
}

DWORD ZApp::GetHeight()
{
	return m_Height;
}

DWORD ZApp::GetClientWidth()
{
    return m_ClientWidth;
}

DWORD ZApp::GetClientHeight()
{
    return m_ClientHeight;
}

LRESULT CALLBACK ZApp::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return ZApplication::MsgProc(hWnd, uMsg, wParam, lParam);
}

BOOL ZApp::Shutdown()
{
	return TRUE;
}

BOOL ZApp::Init()
{
	std::cout << "Window client size: " << m_ClientWidth << "x" << m_ClientHeight << std::endl;
    std::cout << (float)m_ClientHeight / (float)m_ClientWidth << std::endl;

	m_pGraphics = new ZGraphics(GetHWnd(), (float)m_ClientHeight/ (float)m_ClientWidth, m_ClientWidth, m_ClientHeight);

	ShowMouse(TRUE);

	return TRUE;
}

BOOL ZApp::Frame()
{
	// timeGetTime() 함수는 시스템이 시작된 후 경과된 시간을 밀리초(ms) 단위로 반환합니다.
	DWORD timeValue = timeGetTime();
	// 경과 시간을 초 단위로 변환합니다. (1000ms = 1s)
	double dValue = timeValue / 1000.0;
	// sin 함수를 사용하여 시간의 흐름에 따라 0.0 ~ 1.0 사이를 부드럽게 왕복하는 값을 계산합니다.
	// sin(dValue)의 결과는 -1.0 ~ 1.0 이므로, 이를 0.0 ~ 1.0 범위로 정규화합니다.
	const float c = (float)sin(dValue) / 2.0f + 0.5f;
	// 계산된 'c' 값을 사용하여 화면 배경색을 동적으로 변경합니다.
	// Red와 Green 채널이 'c' 값에 따라 변하므로, 배경색이 파란색(0,0,1)과 청록색(1,1,1) 사이를 오가게 됩니다.
	m_pGraphics->ClearBuffer(c, c, 1.0f);


	//m_pGraphics->DrawTestTriangle();
    //m_pGraphics->DrawIndexedTriangle();
    //m_pGraphics->DrawConstantBuffer((float)dValue);

	// 윈도우 내에서 현재 마우스 위치
	RECT rect;
	GetWindowRect(GetHWnd(), &rect);
	POINT pt;
	GetCursorPos(&pt);
	pt.x -= rect.left;
	pt.y -= rect.top;
	//std::cout << pt.x << " " << pt.y << std::endl;

    //m_pGraphics->DrawConstantBufferWithDXMath(
    //    (float)dValue,
    //    ((float)pt.x / ((float)m_ClientWidth / 2.0f)) - 1.0f,
    //    (-(float)pt.y / ((float)m_ClientHeight / 2.0f)) + 1.0f
    //);

    //m_pGraphics->DrawCube(
    //    (float)dValue,
    //    ((float)pt.x / ((float)m_ClientWidth / 2.0f)) - 1.0f,
    //    (-(float)pt.y / ((float)m_ClientHeight / 2.0f)) + 1.0f
    //);


    // 고정위치
    m_pGraphics->DrawCubeDepth(
        -(float)dValue,
        0.0f,
        0.0f
    );

    // 마우스로 y축으로 깊이 조정
    m_pGraphics->DrawCubeDepth(
        (float)dValue,
        ((float)pt.x / ((float)m_ClientWidth / 2.0f)) - 1.0f,
        (-(float)pt.y / ((float)m_ClientHeight / 2.0f)) + 1.0f
    );


	// 렌더링된 후면 버퍼를 화면에 표시합니다.
	m_pGraphics->EndFrame();
	return TRUE;
}