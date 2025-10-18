#include "stdafx.h"

#include "Human.h"
#include "Student.h"
#include "My_Class.h"

// 클래스 문법
// class 클래스명
// {
//    자료형 필드명's;
//    반환형 메소드명( 매개변수 );
// };

// 클래스는 일반적으로 헤더파일과 소스파일로 구분해서 만든다.
// 일반적으로 클래스를 만들면 1개의 헤더파일과 1개의 소스파일이 사용된다.
// 헤더파일은 기본적으로 선언부분으로 이루어져 있고, 소스 파일은 해당하는 클래스의 정의 부분으로 이루어져 있다.

int main()
{
    srand( time( NULL ) );
    setlocale( LC_ALL, "ko_KR.UTF-8" );

    // 객체 생성이란, 어떨때 객체 생성인가?
    // 자신의 메모리 공간을 가질 때를 객체 생성이라 한다.
    // Human man;                      // 객체 생성
    // Human* girl = NULL;             // 변수 선언
    // // strcpy_s( man._name, sizeof( man._name ), "홍길동" );
    // // man._age = 20;
    // // man._isMan = true;
    // if ( !girl )
    //     girl = new Human;           // 객체 생성
    // // strcpy_s( girl -> _name, sizeof( girl -> _name ), "이영희" );
    // // girl -> _age = 18;
    // // girl -> _isMan = false;
    // man.InitalizeInfo( "김철수", 18, true );
    // girl -> InitalizeInfo( "이영희", 18, false );
    // girl -> ShowPrintInfo();
    // man.ShowPrintInfo();
    // man.Laugh();
    // girl -> Laugh();
    // if ( girl )
    // {
    //     delete girl;
    //     girl = NULL;
    // } // if()

    // 문제 1
    // RectangleClass rect1;
    // RectangleClass rect2;
    // RectangleClass rect3;
    // rect1.InitalizeInfo( 10, 10 );
    // rect2.InitalizeInfo( 20, 30 );
    // rect3.InitalizeInfo( 50, 40 );
    // rect1.ShowPrintInfo( rect1.GetWidth(), rect1.GetHeight() );
    // rect1.ShowPrintRectangleInfo();
    // rect2.ShowPrintInfo( rect2.GetWidth(), rect2.GetHeight() );
    // rect2.ShowPrintRectangleInfo();
    // rect3.ShowPrintInfo( rect3.GetWidth(), rect3.GetHeight() );
    // rect3.ShowPrintRectangleInfo();
    // rect1.SetHeight( 20 );
    // rect1.SetWidth( 30 );
    // rect1.ShowPrintInfo( rect1.GetWidth(), rect1.GetHeight() );
    // rect1.ShowPrintRectangleInfo();

    // Student boy;
    // Human* point = &boy;
    // boy.InitalizeInfo( "김철수", 16, true, 3, 14, 3, "열심히노는중" );
    // boy.ShowPrintInfo();
    // point->ShowPrintInfo();
    
    // My_Class Im_Si_1, Im_Si_2;
    // cout << "MyClass::Number >>> " << My_Class::Number << endl;
    // cout << "Im_Si_1.Number >>> " << Im_Si_1.Number << ", Im_Si_2.Number >>> " << Im_Si_2.Number << endl;
    // cout << "Im_Si_1.Count >>> " << Im_Si_1.Count << ", Im_Si_2.Count >>> " << Im_Si_2.Count << endl;
    // cout << "=====================================================================================" << endl;
    // My_Class::Number = 100;
    // Im_Si_1.Count = 7;
    // cout << "MyClass::Number >>> " << My_Class::Number << endl;
    // cout << "Im_Si_1.Number >>> " << Im_Si_1.Number << ", Im_Si_2.Number >>> " << Im_Si_2.Number << endl;
    // cout << "Im_Si_1.Count >>> " << Im_Si_1.Count << ", Im_Si_2.Count >>> " << Im_Si_2.Count << endl;
    // cout << "=====================================================================================" << endl;
    // Im_Si_1.Number = 5;
    // Im_Si_2.Count = 128;
    // cout << "MyClass::Number >>> " << My_Class::Number << endl;
    // cout << "Im_Si_1.Number >>> " << Im_Si_1.Number << ", Im_Si_2.Number >>> " << Im_Si_2.Number << endl;
    // cout << "Im_Si_1.Count >>> " << Im_Si_1.Count << ", Im_Si_2.Count >>> " << Im_Si_2.Count << endl;
    // cout << "=====================================================================================" << endl;
    // cout << "23 + 65 + 91 >>> " << My_Class::Add_Three_Number( 23, 65, 91 ) << endl;
    // cout << "23 * 65 * 91 >>> " << Im_Si_1.Multy_Three_Number( 23, 65, 91 ) << endl;

    for( int n = 1 ; n < 10 ; n++ )
    {
        cout << "Count " << n << "!!" << endl;
        Sleep( 500 );
    }

    return 0;
} // main()