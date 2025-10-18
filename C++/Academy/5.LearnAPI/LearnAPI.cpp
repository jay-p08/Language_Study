#include "framework.h"
#include "LearnAPI_OutIn.h"
#include <winuser.h>


#define Max_LOADSTRING 100

HINSTANCE hInst;
WCHAR szTitle[Max_LOADSTRING];                  // 제목 표시줄 텍스트
WCHAR szWindowClass[Max_LOADSTRING];            // 기본 창 클래스 이름
HWND hWnd;

TCHAR _szStringBuffer1[MAX_STRINGBUFFER] = _T( "안녕하세요~" );

LRESULT CALLBACK WndProc( HWND, UINT, WPARAM, LPARAM );

int APIENTRY wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
    UNREFERENCED_PARAMETER( hPrevInstance );
    UNREFERENCED_PARAMETER( lpCmdLine );

    LoadStringW( hInstance, IDS_APP_TITLE, szTitle, Max_LOADSTRING );
    LoadStringW( hInstance, IDC_LEARNAPI, szWindowClass, Max_LOADSTRING );

    // 1. 윈도우 클래스를 등록
    WNDCLASSEX wndex;
    wndex.cbSize = sizeof( WNDCLASSEX );
    wndex.style = CS_HREDRAW | CS_VREDRAW;
    wndex.lpfnWndProc = WndProc; // 메세지 프로시져
    wndex.cbClsExtra = 0;
    wndex.cbWndExtra = 0;
    wndex.hInstance = hInst = hInstance;
    wndex.hIcon = LoadIcon( NULL, IDI_APPLICATION );
    wndex.hIconSm = LoadIcon( hInst, MAKEINTRESOURCE( IDI_SMALL ) );
    wndex.hCursor = LoadCursor( NULL, IDC_CROSS );
    wndex.hbrBackground = (HBRUSH)GetStockObject( BLACK_BRUSH );
    wndex.lpszMenuName = MAKEINTRESOURCE( IDC_LEARNAPI );
    wndex.lpszClassName = szWindowClass;
    RegisterClassEx( &wndex );

    // 2. 윈도우 만들기
    CreateWindowEx( WS_EX_OVERLAPPEDWINDOW, szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL );
    if( !hWnd )
        return 0;
    ShowWindow( hWnd, nCmdShow );

    // 3. 메세지 루프 생성
    HDC hdc = GetDC( hWnd );

    // TextOut은 문자열을 화면의 지정한 위치에 출력한다.
    // 함수 원형 : BOOL TextOut( HDC hdc, int nXStart, int nYStart, LPCTSTR lpStr, int sbStr );
    // 반환 : 성공하면 TRUE, 실패하면 FALSE를 반환한다.
    // 매개변수 : nXStart, nYStart는 출력 위치를 지정한다.
    // lpstr은 출력 문자열을 지정한다.
    // sbStr은 출력 문자열의 길이를 지정한다.
    // TCHAR text[20] = L"안녕하세요~";
    // int len = lstrlen( text );
    // TextOut( hdc, 100, 50, text, len );
    // TextOut( hdc, 200, 100, text, len );

    MSG msg;
    while( GetMessage( &msg, NULL, 0, 0 ) )
    {
        TranslateMessage( &msg );
        DispatchMessage( &msg );
    }

    ReleaseDC( hWnd, hdc );
    return (int)msg.wParam;
}

// 4. 메세지 프로시져 구현
LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    switch ( message )
    {
        // 2. BeginPaint를 이용하여 DC를 얻어온다. 이 방법은 WM_PAINT에서만 사용 가능하다.
        // 함수 원형 : HDC BeginPaint( HWND hWndm LPPAINTSTRUCT lpPaint );
        // 반환 : DC의 핸들을 반환한다.
        // 매개변수 : 출력하고자 하는 윈도우의 핸들, 그리기 정보를 받는 구조체를 넣어준다.
        case WM_PAINT :
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint( hWnd, &ps );

            int len = lstrlen( _szStringBuffer1 );
            TextOut( hdc, 100, 50, _szStringBuffer1, len );
            TextOut( hdc, 200, 100, _szStringBuffer1, len );

            // 그리기 작업이 끝나면 EndPaint를 호출한다.
            EndPaint( hWnd, &ps );
            break;
        case WM_COMMAND :
            switch ( LOWORD( wParam ) )
            {
                case IDM_EXIT :
                    DestroyWindow( hWnd );
                    break;
            }
        case WM_DESTROY :
            PostQuitMessage( 0 );
            break;
    }

    return DefWindowProc( hWnd, message, wParam, lParam );
}