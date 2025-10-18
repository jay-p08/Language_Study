#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <windows.h>

int main() {
    srand( time( 0 ) );

    int max = 0, min;
    int num = 0;
    int i = 1;

    do
    {
        printf( "구구단중 출력 다수를 입력하세요. ( 2 ~ 9, 999입력시 종료 ) >>> " );
        scanf( "%d", &num );

        for( i = 1 ; i <= 9 ; i++ )
        {
            printf( "%d * %d = %d\n", num, i, num * i );
        } // for()

        if( num == 999 ) break;
    } while ( 1 );
    

    system( "pause" );
    return 0;
}