// Temp.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Temp.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                     // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];       // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING]; // 기본 창 클래스 이름입니다.
HWND hWnd;

TCHAR _szStringBuffer1[MAX_STRINGBUFFER] = _T("안녕하세요~");
TCHAR _szStringBuffer2[MAX_STRINGBUFFER] = _T("으하하핳핳화화호하허ㅏ허햐후ㅑ후ㅐㅑㅎ햐ㅓㅎㅎ");

POINT _pos = {550, 320};
TCHAR _szModel[] = L"<A>";
tagRECT _drawPosition = {
    0,
};
bool _isDraw = FALSE;

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // MessageBox는 화면에 대화 상자를 생성합니다.
    // 함수 원형 : int MessageBox( HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType )
    // 반환 : 실패시 0을 반환, 성공시 uType에 따라 생성되는 버튼의 선택에 의해 반환값이 달라짐.
    // 매개변수 : hWnd는 대화 상자의 소유주 핸들을 넣어줍니다. 소유주가 없으면 NULL을 지정한다.
    // 매개변수 : lpText는 표시할 메시지이고,

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TEMP, szWindowClass, MAX_LOADSTRING);
    LoadString(hInstance, IDS_SAMPLESTRING, _szStringBuffer1, MAX_STRINGBUFFER);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }
    // MessageBox( _hWndMain, L"윈도우가 생성되었습니다", L"알 림", MB_OK);

    HDC hdc = GetDC(hWnd);

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

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TEMP));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        // SetPixel(hdc, rand() % 400 + 610, rand() % 400 + 300, RGB(rand() % 256, rand() % 256, rand() % 256));
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    /*while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        SetPixel(hdc, rand() % 400 + 610, rand() % 400 + 300, RGB(rand() % 256, rand() % 256, rand() % 256));
    }*/

    ReleaseDC(hWnd, hdc);
    return (int)msg.wParam;
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

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TEMP));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_TEMP);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
        case IDM_DRAW_LINE:
            break;
        case IDM_DRAW_RECT:
            break;
        case IDM_DRAW_ELLIPS:
            break;
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
    case WM_CHAR:
    {
        int len = lstrlen(_szStringBuffer2);
        _szStringBuffer2[len] = (TCHAR)wParam;
        _szStringBuffer2[len + 1] = 0; // '\0';
        InvalidateRect(hWnd, NULL, TRUE);
    }
    break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            MessageBox(NULL, L"ESC키를 눌렀습니다!!", L"알 림", MB_OK);
            break;
            {
            case VK_LEFT:
            case 'A':
                _pos.x -= 8;
                break;
            case VK_RIGHT:
            case 'D':
                _pos.x += 8;
                break;
            case VK_UP:
            case 'W':
                _pos.y -= 8;
                break;
            case VK_DOWN:
            case 'S':
                _pos.y += 8;
                break;
            }
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case WM_KEYUP:
            break;
        case WM_LBUTTONDOWN:
            _drawPosition.left = LOWORD(lParam);
            _drawPosition.top = HIWORD(lParam);
            break;
        case WM_LBUTTONUP:
            _drawPosition.right = LOWORD(lParam);
            _drawPosition.bottom = HIWORD(lParam);
            break;
        case WM_LBUTTONDBLCLK:
            break;
        case WM_MOUSEMOVE:
        {
            if (wParam & MK_LBUTTON)
            {
                int x = LOWORD(lParam);
                int y = HIWORD(lParam);
                wprintf(_szStringBuffer2, L"MousePos[X:%d, Y:%d]", x, y);
                _drawPosition.right = x;
                _drawPosition.bottom = y;
                _isDraw = TRUE;
                InvalidateRect(hWnd, NULL, TRUE);
            }
        }
        break;
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            // 2. BeginPaint를 이용하여 DC를 얻어온다. 이 방법은 WM_PAINT에서만 사용 가능하다.
            // 함수 원형 : HDC BeginPaint( HWND hWndm LPPAINTSTRUCT lpPaint );
            // 반환 : DC의 핸들을 반환한다.
            // 매개변수 : 출력하고자 하는 윈도우의 핸들, 그리기 정보를 받는 구조체를 넣어준다.
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            int len = lstrlen(_szStringBuffer1);
            // SetTextAlign은 출력되는 TextOut의 문자열을 정렬하는 함수이다.
            // 함수 원형 : UINT SetTextAlign( HDC hdc, UINT align );
            // 반환 : 출력 실패시 GDI_ERROR를 반환하고, 성공시 바꾸기전ㅇ의 ALign값을 반환한다.
            // 매개변수 : align은 정렬 방법을 지정한다.

            // TextOut( hdc, 100, 50, _szStringBuffer1, len );
            // int align = SetTextAlign( hdc, TA_RIGHT | TA_BASELINE );
            // TextOut( hdc, 200, 100, _szStringBuffer1, len );
            // SetTextAlign( hdc, align );
            // TextOut( hdc, 100, 70, _szStringBuffer1, len );

            // DrawText는 문자열을 사각형 영역 안에서 설정에 의해 출력되는 함수이다.
            // 함수 원형 : int DrawText( HDC hdc, LPCTSTR lpStr, int nCnt, LPRECT lpRect, UINT uFormat )
            // 반환 : 출력 성공시 논리 단위의 텍스트 높이를 반환하고, 실패시 0을 반환.
            // 매개변수 : lpStr은 출력 문자열을 넣어준다.
            // 매개변수 : nCnt 출력 문자열의 길이를 넣어준다. -1을 넣으면 문자열의 null까지 출력한다.
            // 매개변수 : lpRect 출력 문자열의 서식을 지정할 사각형 영역을 넣어준다.
            // 매개변수 : uFormat 출력 문자열의 서식을 넣어준다.
            RECT rc1 = {100, 110, 200, 310};
            Rectangle(hdc, rc1.left - 1, rc1.top - 1, rc1.right + 1, rc1.bottom + 1);
            DrawText(hdc, _szStringBuffer1, -1, &rc1, DT_CENTER | DT_WORDBREAK);
            TextOut(hdc, 60, 400, _szStringBuffer2, DT_CENTER | DT_WORDBREAK);

            // 기초 그래픽 출력
            // 점그리기
            // SetPixel은 화면의 지정 위치에 지정한 색으로 점을 그린다.
            // 함수 원형 : COLORREF SetPixel( HDC hdc, int x, int y, COLORREF color )
            // 반환 : 점을 그리고 해당 점이 그려지는 위치의 원래색의 값을 반환한다. 그리기 실패시 -1.
            // 매개변수 : x, y는 점을 그리는 위치이고, color는 점의 색을 지정한다.
            for (int n = 0; n < 10; n++)
                SetPixel(hdc, 300 + n, 50, RGB(255, 0, 0));

            // 선그리기
            // MoveToEx와 LineTo를 이용해 화면에 선을 그린다.
            // 함수 원형 : DWORD MoveToEx( HDC hdc, int x, int y, LPPOINT lppt )
            // 반환 : 시작위치 설정이 정상적으로 처리가 되면 0이 아닌 수를 반환한다.
            // 매개변수 : x, y는 시작 위치 이고, lppt는 POINT 구조체 포인터로 이전 위치를 지정하는데 없으면 NULL을 지정한다.
            // 함수 원형 : BOOL LineTo( HDC hdc, int x, int y )
            // 반환 : 끝위치를 설정하여 선을 그리는데 성공하면 TRUE, 실패 FALSE.
            // 매개변수 : x, y는 마지막 위치
            MoveToEx(hdc, 300, 100, NULL);
            LineTo(hdc, 300, 200);
            // MoveToEx( hdc, 600, 200, NULL );
            LineTo(hdc, 400, 300);
            LineTo(hdc, 500, 400);
            LineTo(hdc, 600, 500);

            // 사각형그리기
            // Rectangle을 이용해 화면에 사각형을 그린다,
            // 함수 원형 : BOOL Rectangle( HDC hdc, int left, int top, int right, int bottom )
            // 반환 : 그림 그리기 성공 시 TRUE이고, 실패면 FALSE.
            // 매개변수 : left, top, right, bottom은 사각형의 꼭지점 위치를 넣는다.
            Rectangle(hdc, 300, 50, 900, 600);

            // 타원그리기
            // Ellipse는 화면에 원 or 타원을 그린다.
            // 함수 원형 : BOOL Ellipse( HDC hdc, int left, int top, int right, int bottom )
            // 반환 : 그림 그리기 성공 시 TRUE이고, 실패하면 FALSE.
            // 매개변수 : left, top, right, bottom은 원의 중앙 위치를 넣는다.
            Ellipse(hdc, 600, 50, 900, 350);

            MoveToEx(hdc, _drawPosition.left, _drawPosition.top, NULL);
            LineTo(hdc, _drawPosition.right, _drawPosition.bottom);

            TextOut(hdc, _pos.x, _pos.y, _szModel, lstrlen(_szModel));
            TextOut(hdc, 50, 30, _szStringBuffer2, lstrlen(_szStringBuffer2));

            EndPaint(hWnd, &ps);

            switch (_drawType)
            {
                case LINE :
                    MoveToEx( hdc, _drawPosition.left, _drawPosition.top, NULL );
                    LineTo( hdc, _drawPosition.right, _drawPosition.bottom );
                    break;
                case RECTANGLE :
                    Rectangle( hdc, _drawPosition.left, _drawPosition.top, _drawPosition.right, _drawPosition.bottom );
                    break;
                case ELLIPSE :
                    Ellipse( hdc, _drawPosition.left, _drawPosition.top, _drawPosition.right, _drawPosition.bottom );
                    break;
            }
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