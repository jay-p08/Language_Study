#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#include <windows.h>

#define _ARRAY_COUNT_   6
#define _ROW_COUNT_     2
#define _COL_COUNT_     5

enum eParam
{
    a_COUNT = 5,
}; // eParam

int main() {
    srand( time( 0 ) );
    setlocale(LC_ALL, "ko_KR.UTF-8");

    #pragma region 배열
    // 배열은 여러개의 자료가 동일한 자료형을 갖는 기억 장소로, 메모리상에 연속적으로 만들어진다.
    // 문법
    // 자료형 배열이름[배열수( 상수 )];
    // 배열 내에 있는 값을 수정할 때는 대괄호 연산자를 이용해 방에 직접 접근하여 사용한다.
    // 방 번호는 0번부터 시작이다.

    // 1차원 배열의 선언과 초기화
    // int n;
    // int arr[a_COUNT] = { 0, };                              // 배열 선언과 0으로의 초기화
    // int datas[_ARRAY_COUNT_] = { 11, 22, 33, 44, 55, 66 };  // 배열 선언과 동시에 초기화
    // // datas = { 1, 2, 3, 4, 5, 6 };
    // arr[1] = 99;
    // for( n = 0 ; n < a_COUNT ; n++ )
    // {
    //     printf( "arr[%d] = %d\n", n, arr[n] );
    // } // for()
    // for( n = 0 ; n < _ARRAY_COUNT_ ; n++ )
    // {
    //     printf( "datas[%d] = %d\n", n, datas[n] );
    // } // for()

    // 다차원 배열
    // 다차원 배열은 같은 자료형의 요소가 2개 이상의 분류에 의해 정리되어 처리할 때 사용된다.
    // 문법
    // 자료형 배열이름...[개수][개수];
    // float averageArr[ _ROW_COUNT_ ][ _COL_COUNT_ ] = { 0, };
    // int n, m;
    // int totalCount = _ROW_COUNT_ * _COL_COUNT_;
    // for ( n = 0 ; n < _ROW_COUNT_ ; n++ )
    // {
    //     for ( m = 0 ; m < _COL_COUNT_ ; m++ )
    //     {
    //         averageArr[ n ][ m ] = (float)( rand() % 551 + 450 ) / 10;
    //     } // for()
    // } // for()
    // for ( n = 0 ; n < totalCount ; n++ )
    // {
    //     int row = n / _COL_COUNT_;
    //     int col = n % _COL_COUNT_;
    //     printf( "averageArr[%u][%u] = %1.1f\n", row, col, averageArr[ row ][ col ] );
    // } // for()
    
    #pragma endregion

    #pragma region 포인터

    // 포인터는 메모리상의 위치를 정수로 표현한 값이다. 그래서 포인터를 한글로 주소 또는 번지 라고 한다.
    // 문법
    // 자료형* 변수명;
    // 일반 변수의 주소를 받아오려면 일반 변수 앞에 &연산자를 사용하면 된다.
    // 주소 변수( 포인터 )의 앞에 *연산자를 사용하면 주소 변수가 가진 주소에 들어있는 값을 가져온다.
    
    // int number = 10;
    // char ch = 'z';
    // int* pNum = &number;
    // char* pCha = &ch;
    // printf( "int size is %ubyte\n", sizeof( int ) );
    // printf( "char size is %ubyte\n", sizeof( char ) );
    // printf( "int's pointer size if %ubyte\n", sizeof( pNum ) );
    // printf( "char's pointer size if %ubyte\n", sizeof( pCha ) );
    // printf( "number's adress : %u, number's Value : %d\n", &number, number );
    // printf( "pNum's adress : %u, pNum's Value : %u, pNum's Addr Value of Value : %d\n", &pNum, pNum, *pNum );
    // printf( "ch's adress : %u, ch's Value : %c\n", &ch, ch );
    // printf( "pCha's adress : %u, pCha's Value : %u, pCha's Addr Value of Value : %d( %c )\n", &pCha, pCha, *pCha, *pCha );
    // int sampleArr[ _ARRAY_COUNT_ ] = { 11, 22, 33, 44, 55, 66 };
    // char sampleString[] = "ABCDEFGHIJK";
    // int* pAddr = 0;
    // int n;
    // int size = sizeof( sampleString );
    // int stringLength = strlen( sampleString );
    // printf( "size = %u, stringLength = %u\n", size, stringLength );
    // printf( "sampleArr's Address : %u, sampleArr's Value : %u\n", &sampleArr, sampleArr );
    // for ( n = 0 ; n < _ARRAY_COUNT_ ; n++ )
    // {
    //     printf( "sampleArr[%u]'s Address : %u, sampleArr[%u]'s Value : %d\n", n, &sampleArr[n], n, sampleArr[n] ); 
    //     printf( "sampleArr + id : %u\n", sampleArr + n );
    // } // for()
    // printf( "=====================================================================================\n" );
    // for( n = 0 ; n < stringLength ; n++ )
    // {
    //     printf( "sampleString[%u]'s Address : %u, sampleString[%u]'s Value : %c\n", n, &sampleString[n], n, sampleString[n] );
    //     printf( "sampleString + id : %u\n", sampleString + n );
    // } // for()
    // printf( "=====================================================================================\n" );
    
    // pAddr = sampleArr;
    // for( n = 0 ; n < _ARRAY_COUNT_ ; n++ )
    // {
    //     // printf( "sampleArr[%u] = %d\n", n, pAddr[n] );
    //     pAddr = sampleArr + n;
    //     printf( "sampleArr[%u] = %d\n", n, *pAddr );
    // } // for()

    // 다중 포인터
    // 디증 포인터는 주소변수의 주소를 가지는 주소 변수를 말한다.
    // 문법
    // 자료형**... 변수명;

    #pragma endregion
    
    #pragma region 동적 할당
    // 동적 할당이란 프로그래머가 필요에 의해 사용할 메모리 공간을 할당 받는 것으로
    // 사용이 끝나면 해지를 꼭!! 해줘야 한다.
    // 메모리 할당 문법
    // 1. 주소 변수 = ( 자료형 * )malloc( 바이트 수 );
    // 2. 주소 변수 = ( 자료형 * )calloc( 개수, 바이트 수 );
    // 메모리 해지 문법
    // free( 주소 변수 );

    // int* pNum = 0;
    // pNum = ( int* )malloc( sizeof( int ) );
    // *pNum = 10;
    // printf( "pNum = %u, pNum's size = %u\n", pNum, sizeof( pNum ) );
    // printf( "pNum's address = %u\npNum's Value By Value = %d\n", &pNum, *pNum );
    // free( pNum );

    // int* nums = 0;
    // int count = 5, n = 0;
    // if( nums == 0 )
    //     nums = ( int* )calloc( count, sizeof( int ) );
    // for( n = 0 ; n < count ; n++ )
    //     nums[n] = rand();
    // for( n = 0 ; n < count ; n++ )
    //     printf( "nums[%u] = %d\n", n, nums[n] );
    // if( nums != 0 )
    // {
    //     free( nums );
    //     nums = 0;
    // } // if()
    
    // 문제
    // int count = 0, n = 0;
    // int highScore = 0;
    // int sum = 0;
    // float avg = 0;
    // int min, max;
    // int* pStudent = 0;
    // printf( "학생이 몇명이 있나요 >>> " );
    // scanf( "%d", &count );
    // if( pStudent == 0 )
    //     pStudent = ( int* )malloc( count * sizeof( int ) );
    // printf( "최저 점수는 몇점입니까 >>> " );
    // scanf( "%d", &min );
    // printf( "최고 점수는 몇점입니까 >>> " );
    // scanf( "%d", &max );
    // for( n = 0 ; n < count ; n++ )
    // {
    //     pStudent[n] = rand() % ( max - min + 1 ) + min;
    //     sum += pStudent[n];
    //     printf( "%d번째 학생 점수 >>> %d\n", n+1, pStudent[n] );
    // } // for()
    // avg = (float)sum / count;
    // for( n = 0 ; n < count ; n++ )
    // {
    //     if( pStudent[n] > avg )
    //         highScore++;
    // } // for()
    // printf( "평균점수는 %.1f점이고, 평균보다 높은 점수의 학생은 %d명입니다.\n", avg, highScore );
    // if( pStudent != 0 )
    // {
    //     free( pStudent );
    //     pStudent = 0;
    // } // if()

    // int rows = 5;
    // int columns = 8, n;
    // int** numbers = 0;
    // if ( numbers == 0 )
    // {
    //     numbers = ( int** )malloc( rows * sizeof( int* ) );
    //     for ( n = 0 ; n < count ; n++ )
    //         numbers[n] = ( int* )malloc( columns * sizeof( int ) );
    // } // if()
    // free( numbers );

    #pragma endregion
    
    system( "pause" );
    return 0;
}