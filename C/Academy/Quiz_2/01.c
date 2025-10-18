#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <windows.h>

int main() {
    int num = 0, sum = 0;
    int i = 0;

    printf( "정수를 입력하세요 >>> " );
    scanf( "%d", &num );

    for( i = 0 ; i < num ; i++ )
    {
        sum += i+1;
    } // for()
    if( num < 1 )
    {
        printf( "종료합니다!!" );
    } // if()
    else
    {
        printf( "1 ~ %d까지의 총합은 %d입니다.", num, sum );
    } // else

    system( "pause" );
    return 0;
}