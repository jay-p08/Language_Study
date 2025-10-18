#include <stdio.h>

int main() {
    int year = 0;

    printf( "출생년도를 입력하세요 >>> " );
    scanf( "%d", &year );
    printf( "당신의 나이는 %d세입니다.\n", ( 2025-year ) + 1 );

    return 0;
}