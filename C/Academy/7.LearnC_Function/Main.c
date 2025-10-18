#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#include <windows.h>

#define _ARRAY_Size_        7

void ShowScreenFrame();
float randf();
void PrintIntegerArrayValue( int* arr, int count, char* name );
int GetRandomRange( int minimum, int maximum );
void ArrayScanner(int* array, int count, int min, int max );

int main() {
    srand( time( 0 ) );
    setlocale(LC_ALL, "ko_KR.UTF-8");

    // ShowScreenFrame();

    // int n = 0;
    // for( n = 0 ; n < 5 ; n ++ )
    //     printf( "임의의 실수 [%f]\n", randf() );
    // ShowScreenFrame();

    // int sample[] = { 1, 2, 3, 4, 5, 6 };
    // int buff[] = { 99, 88, 77 };
    // int count1 = sizeof( sample ) / sizeof( int );
    // int count2 = sizeof( buff ) / sizeof( int );
    // PrintIntegerArrayValue( sample, count1, "sample" );
    // printf( "============================================\n");
    // PrintIntegerArrayValue( buff, count2, "buff" );
    // ShowScreenFrame();

    // int n;
    // int arry[_ARRAY_Size_] = { 0, };
    // for( n = 0 ; n < _ARRAY_Size_ ; n++ )
    //     arry[n] = GetRandomRange( 1, 100 );
    // PrintIntegerArrayValue( arry, _ARRAY_Size_, "arry" );
    // ShowScreenFrame();

    // 문제
    int count, n;
    int min, max;
    int maxStudent = 0, maxStudentIndex = 0;
    int* pStudent = 0;
    printf( "학생수를 입력하세요 >>> " );
    scanf( "%d", &count );
    printf( "점수 범위를 입력하세요( 최소 최대 ) >>> " );
    scanf( "%d %d", &min, &max );
    pStudent = (int*)malloc( count * sizeof( int ) );
    ArrayScanner( pStudent, count, min, max );
    for( n = 0 ; n < count ; n++ )
    {
        printf( "%d번째 학생 점수 >>> %d\n", n + 1, pStudent[n] );
        if( maxStudent < pStudent[n] )
        {
            maxStudent = pStudent[n];
            maxStudentIndex = n + 1;
        } // if()
    }
    printf( "%d명의 학생중 최고점은 %d점이고, 최고점자는 %d번째 학생입니다.\n", count, maxStudent, maxStudentIndex );

    system( "pause" );
    return 0;
} // main()

// 함수
// 함수는 기본적으로 표준함수와 사용자 정의 함수로 나누어 진다.
// 함수는 반복적 작업을 피하고 코드의 재사용을 목적으로 만들어진다.
// 또, 함수는 프로그램의 가독성을 올리기위한 목적으로 만들기도 한다.
// 함수를 만들 때 주의 사항
// 1. 함수 안에 함수를 만들 수 없다.
// 2. 임의의 함수를 사용할 때는 사용하는 함수가 현재 함수보다 위에 선언 또는 정의가 되어 있어야 한다.
// * 함수를 만들때는 하나의 함수가 하나의 기능이 되도록 하는 것이 좋다.
// 문법
// ( 한정자 ) 반환형 함숭이름( 매개변수자료형, 매개변수이름, ...... ) <= 매개변수는 0 ~ n 여러개를 만들 수 있다.
// {
//    명령문;
// }
// 한정자 : 여러가지를 동시에 사용 할 수 있고, 사용 하지 않아도 된다.( 예. static, inline ...... )
// 반환형 : 자료형으로서 함수가 종료될 때 반환하는 값의 자료형을 지정한다( 반환값이 없을시는 void로 지정한다. )
// 함수이름 : 사용자가 이름을 지정하는 것으로 사용자 마음대로 지정해도 된다.
//           ( 단, 권장 사항으로 함수의 용도 또는 목적에 맞는 이름으로 지정한다. )
// 매개변수 : 외부에서 함수 내로 가져와야 하는 정보가 있을 경우 만들어 준다.
//           몇개는 만들어도 상관 없고, 외부에서 정보를 가져올 필요가 없는 경우 만들지 않아도 된다.

// 반환값과 매개변수가 모두 없는 경우.
void ShowScreenFrame()
{
    printf( "┌──────────────┐\n" );
    printf( "│     종료     │\n" );
    printf( "└──────────────┘\n" );

    return;
} // ShowScreenFrame()
// 반환값은 있지만 매개변수가 없는 경우.
float randf()
{
    float result = rand() / 1000.0f;
    return result;
} // randf()
// 반환값은 없고, 매개변수가 있는 경우.
void PrintIntegerArrayValue( int* arr, int count, char* name )
{
    int n;
    for ( n = 0 ; n < count ; n++ )
        printf( "%s[%d] = %d\n", name, n, arr[n] );

    return;
} // PrintIntegerArrayValue()
// 반환값과 매개변수가 모두 있는 경우.
int GetRandomRange( int minimum, int maximum )
{
    return rand() % ( maximum - minimum + 1 ) + minimum;
} // GetRandomRange()
// 문제
void ArrayScanner(int* array, int count, int min, int max )
{
    int n;
    for( n = 0 ; n < count ; n++ )
        array[n] = GetRandomRange( min, max );
    return;
} // ArrayScanner()