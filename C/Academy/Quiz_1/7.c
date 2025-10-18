#include <stdio.h>

int main() {
    int day = 0;

    printf( "날짜를 입력하세요 >>> " );
    scanf( "%d", &day );

    if( day < 10 ) {
        printf( "%d일은 %d분 입니다.\n", day, day * 1440 );
    } // if
    else {
        printf( "%d일은 %d시 입니다.\n", day, day * 24 );
    } // else


    return 0;
}