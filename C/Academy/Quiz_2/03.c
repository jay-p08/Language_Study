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
        printf( "%d번째 정수 : ", i );
        scanf( "%d", &num );
        if ( num == 0 ) break;
        min = max;

        if ( max < num )
        {
            max = num;
        } // if
        if ( min > num )
        {
            min = num;
        } // if
        
        i++;
    } while ( 1 );

    printf( "입력 정수중 가장 큰 수는 %d입니다.\n", max );
    printf( "입력 정수중 가장 작은 수는 %d입니다.\n", min );
    

    system( "pause" );
    return 0;
}