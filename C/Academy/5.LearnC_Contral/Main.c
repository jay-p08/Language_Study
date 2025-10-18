#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <Windows.h>

int main()
{
    srand( time( 0 ) );

    // 반복문
    // 반복문은 조건이 거짓일 될때까지 명령을 반복해서 수행하도록 하는 제어문이다.
    // 키워드 : while, do while, for

    // 조건문
    // 키워드 : if, if else, else

    // while 문법
    // {
    //      명령문;
    // } while( 조건식 );
    // int number = 1;
    // int limit = 6;

    // do while 문법
    // do {
    //      명령문;
    // } while( 조건식 );

    // for 문법
    // for( 초기화식 ; 조건식 ; 증강식 ){
    //      명령문;
    // }
    // int number = 1;
    // int limit = 6;
    // for ( number = 1 ; number < limit ; number++ )
    // {
    //     // printf( "number = %d\n", number );
    //     printf( "random = %d\n", rand() );
    // }

    // 제어 키워드
    // ( goto는 요새 잘 사용하지 않는 제어문이다 )
    // break는 반복문을 나갈때 사용한다.
    // continue는 반복문에서 해당 반복문을 건너 뛸때 사용된다.
    // 이 두 키워드는 하나의 반복문에만 영향을 준다( 다중 반복문일 경우 가장 가까운 반복문에 영향을 줌 ).
    // int number = 0, loop = 0;
    // int limit = 9;
    // for( ; number <= limit ; number++ )
    // {
    //     // printf( "number = %d\n", number );
    //     if( number > limit / 3 )
    //     {
    //         continue;
    //     } // if
    //     printf( "number = %d\n", number );
    //     // if( number > limit / 2 )
    //     // {
    //     //     break;
    //     // } // if
    // } // for
    // for( loop = 0 ; loop <= limit ; ++loop )
    // {
    //     for( number = 0 ; number <= limit ; number++ ) 
    //     {
    //         if( number % 3 == 0 ) 
    //         {
    //             continue;
    //         }
    //         printf( "number = %d%d\n", loop, number );
    //         if( number > loop )
    //         {
    //             break;
    //         }
    //     }
    // }
    // goto 키워드는 지정한 위치로 명령을 점프하는 제어 키워드이다.
    // goto First;
    // Seconds;
    // printf( "숫자11\n" );
    // printf( "숫자12\n" );
    // printf( "숫자13\n" );
    // printf( "숫자14\n" );
    // goto Third;
    // First;
    // printf( "숫자1\n" );
    // printf( "숫자2\n" );
    // printf( "숫자3\n" );
    // goto Seconds;
    // Third;
    // int limit = 0;
    // int i = 0, j = 0;
    // printf( "반복 횟수를 입력하세요 : " );
    // scanf( " %d", &limit );
    // for( i = 0 ; i < limit ; i++ )
    // {
    //     for( j = 0 ; j < limit ; j++ )
    //     {
    //         if( j < i )
    //         {
    //             printf( " " );
    //         } // if
    //         else 
    //         {
    //             printf( "*" );
    //         } // else
    //     } // for
    //     printf( "\n" );
    // } // for

    system( "pause" );
    return 0;
}