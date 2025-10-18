// 2.LearnAPI_Graphics.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "2.LearnAPI_Graphics.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
TCHAR _szStringBuffer[MAX_STRINGBUFFER] = { 0, };

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY2LEARNAPIGRAPHICS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY2LEARNAPIGRAPHICS));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY2LEARNAPIGRAPHICS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY2LEARNAPIGRAPHICS);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE :
        lstrcpy( _szStringBuffer, L"으ㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏ" );
        break;    
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            // 1. GDI오브젝트를 만든다( 또는 기존 것을 가져온다 ).
            // 2. 만든( 혹은 가져온 ) GDI오브젝트를 그리는 객체에 설정한다( 기존것은 반환 ).
            // 3. 그린다.
            // 4. 다른 설정으로 그릴 것이 있으면 그림을 ㄹ다 그릴 때까지 2, 3번을 반복한다.
            // 5. 원래의 GDI오브젝트로 돌려놓는다.
            // 6. 만든 GDI오브젝트는 모두 삭제한다.

            // 스톡 오브젝트를 이용하여 제공된 GDI Object를 사용
            // 브러쉬 도구를 가져온다.
            // HGDIOBJ hBrush = GetStockObject( DKGRAY_BRUSH );
            // HGDIOBJ hBrush2 = GetStockObject( BLACK_BRUSH );
            // HGDIOBJ hPen = GetStockObject( WHITE_BRUSH );
            // // 가져온 브러쉬 도구를 그리는 객체에 전달하면서 기존 브러쉬 도구는 저장.
            // HGDIOBJ oldBrush = ( HBRUSH )SelectObject( hdc, hBrush );
            // // 그린다
            // Rectangle( hdc, 50, 20, 350, 220 );
            // // 다른 GDI오브젝트로 설정한다.
            // HPEN oldPen = ( HPEN )SelectObject( hdc, hPen );
            // SelectObject( hdc, hBrush2 );
            // // 또 그린다
            // Ellipse( hdc, 250, 100, 580, 400 );
            // // 그림을 다 그리면 원래의 브러쉬로 되돌린다.
            // SelectObject( hdc, oldBrush );
            // SelectObject( hdc, oldPen );

            HPEN newPen1, newPen2, oldPen;
            // Pen을 만들어서 사용
            // CreatePen
            // CreatePen은 새로운 Pen을 만드는 함수이다.
            // 원형 : HPEN CreatePen( int penStyle, int nWith, COLORREF color );
            // 반환 : 새로 만든 Pen의 핸들을 반환.
            // 매개변수 : penStyle은 Pen의 모양( 실선, 점선등 ), nWith는 Pen의 두께, color는 Pen의 색상.
            // newPen1 = CreatePen( PS_SOLID, 3, RGB( 215, 20, 15 ) );
            // newPen2 = CreatePen( PS_DOT, 1, RGB( 240, 195, 20 ) );
            // newPen2 = CreatePen( PS_DASHDOTDOT, 3, RGB( 20, 20, 210 ) );
            // oldPen = ( HPEN )SelectObject( hdc, newPen1 );
            // Rectangle( hdc, 50, 20, 350, 220 );
            // SelectObject( hdc, newPen2 );
            // Ellipse( hdc, 150, 100, 240, 140 );
            // DeleteObject( newPen1 );
            // DeleteObject( newPen2 );

            HBRUSH newSolBrush, newHatBrush, newHatBrush2, oldBrush;
            // Brush를 만들어서 사용
            // CreateSolidBrush
            // CreateSolidBrush는 지정한 색으로 가득 채우는 함수.
            // 원형 : HBRUSH CreateSolidBrush( COLORREF color );
            // 반환 : 새로 만든 SolidBrush의 핸들을 반환하고, 실패하면 NULL을 반환.
            // 매개변수 : color는 채울 색을 지정.
            // CreateHatchBrush
            // CreateHatchBrush는 지정한 색, 지정한 무늬로 가득 채우는 함수.
            // 원형 HBRUSH CreateHatchBrush( int iHatch, COLORREF color );
            // 반환 : 새로 만든 HatchBrush의 핸들을 반환하고, 실패하면 NULL을 반환.
            // 매개변수 : iHatch는 무늬 인덱스를 지정, color는 무늬의 색을 지정
            // newSolBrush = CreateSolidBrush( RGB( 0, 0, 255 ) );
            // newHatBrush = CreateHatchBrush( HS_DIAGCROSS, RGB( 255, 187, 255 ) );
            // newHatBrush2 = CreateHatchBrush( HS_BDIAGONAL, RGB( 0, 255, 255 ) );
            // oldBrush = ( HBRUSH )SelectObject( hdc, newSolBrush );
            // Rectangle( hdc, 50, 20, 350, 270 );
            // SelectObject( hdc, newHatBrush );
            // Ellipse( hdc, 150, 120, 450, 370 );
            // SelectObject( hdc, newHatBrush2 );
            // Ellipse( hdc, 200, 200, 500, 500 );
            // SelectObject( hdc, oldBrush );
            // DeleteObject( newSolBrush );
            // DeleteObject( newHatBrush );
            // DeleteObject( newHatBrush2 );

            HFONT newFont, oldFont;
            // Font를 만들어서 사용
            // CreateFont
            // CreateFont는 폰트의 속성, 크기, 변환등을 설정하여 만드는 함수
            // 원형 : HFONT CreateFont( int nHeight, intn nWidth, int nEscapement, int nOrientation,
            //                          int fnWeight, DWORD dwItalic, DWORD dwUnderline, DWord dwStrikeOut,
            //                          DWORD dwCharSet, DWORD dwOutpercision, DWORD dwClipPercision,
            //                          DWORD dwQuality, DWORD dwPitchAndFamily, LPCTSTR szFace );
            // 반환 : 새로 만든 Font의 핸들을 반환.
            // 매개변수 : nHeight는 높이를 지정하며 0이면 디폴트 크기, nWidth는 폰트의 폭을 지정하며 0이면 디폴트 크기.
            // nEscapement는 폰트의 각도를 지정하고 360분법이며, 3시 방향이 0도로 전체문자열의 각도이다.
            // nOrientation은 글자의 각도를 지정하며 개별문자의 기울기를 설정한다.
            // fnWeight는 글자의 두께를 지정, dwItalic은 기울임체 속성을 지정하며 TRUE / FALSE를 사용한다.
            // dwUnderline은 밑줄 속성을 지정하며 TRUE / FALSE를 사용한다.
            // dwStrikeOut은 관통선 속성을 지정하며 TRUE / FALSE를 사용한다. dwCharSet은 문자Set을 설정한다.
            // dwOutpercision은 출력 정확도 설정으로 보통 0, dwClipPercision은 클리핑 정확도 설정으로 보통 0.
            // dwQuality는 출력 품질 설정으로 논리적 특성을 실질 글꼴 특성에 일치시키는 정도로 보통 0으로 설정.
            // dwPitchAndFamily는 폰트의 피치와 그룹을 설정하며 보통 0, szFace는 글꼴의 이름을 지정한다.
            // CreateFontIndirect
            // 원형 : HFONT CreateFontIndirect( const LOGFONT *lplf );
            // 반환 : 새로 만든 Font의 핸들을 반환.
            // 매개변수 : LOGFONT구조체를 지정한다. LOGFONT구조체 안에 폰트의 설정값들이 들어가 있다.
            // SetTextColor
            // SetTextColor는 글자 색을 바꾸는 함수
            // 원형 : COLORREF setTextColor( HDC hdc, COLORREF colro );
            // 반환 : 사용중인 색을 반환한다. 실패시 CLR_INVALID를 반환.
            // 매개볁수 : color는 글자에 지정할 색.
            // SetBkColor 
            // SetBkColor는 글자의 배경색을 바꾸는 함수
            // 원형 : COLORREF SetBkColor( HDC hdc, COLORREF color );
            // 반환 : 사용중인 색을 반환한다. 실패시 CLR_INVALID를 반환.
            // 매개볁수 : color는 글자 배경에 지정할 색.
            // SetBkMode
            // SetBkMode는 배경 색상의 사용 방법을 설정하는 함수
            // 원형 : int SetBkMode( HDC hdc, int iBkMode );
            // 반환 : 사용중인 백그라운드 모드를 반환, 실패시 0반환.
            // 매개변수 : iBkMode는 두가지로 투명, 불투명만 있다.
            COLORREF oldTextColor, oldBkColor;
            newFont = CreateFont( 50, 0, 0, 0, 10, FALSE, FALSE, FALSE, HANGEUL_CHARSET, 0, 0, 0, 0, L"궁서체" );
            oldBkColor = SetBkColor( hdc, RGB( 0, 255, 0 ) );
            TextOut( hdc, 100, 20, _szStringBuffer, lstrlen( _szStringBuffer ) );
            oldFont = ( HFONT )SelectObject( hdc, newFont );
            oldTextColor = SetTextColor( hdc, RGB( 150, 150, 150 ) );
            TextOut( hdc, 150, 120, _szStringBuffer, lstrlen( _szStringBuffer ) );
            SelectObject( hdc, oldFont );
            SetBkColor( hdc, RGB( 0, 200, 248 ) );
            SetBkMode( hdc, TRANSPARENT );
            TextOut( hdc, 130, 160, _szStringBuffer, lstrlen( _szStringBuffer ) );
            SetBkColor( hdc, oldTextColor );
            SetBkColor( hdc, oldBkColor );
            SetBkMode( hdc, OPAQUE );
            DeleteObject( newFont );

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
