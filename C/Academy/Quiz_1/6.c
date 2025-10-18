#include <stdio.h>

int main() {
    int num1 = 0;
    int isTrue = 0;

    printf( "정수를 입력하세요 >>> " );
    scanf( "%d", &num1 );

    for (int i = 0; i < 25; i++)
    {
        if(( ( num1 >> i ) & 0xFF ) == 11 ) {
            isTrue = 1; break;
        } // if
    } // for

    printf( "입력 정수 [%d]( 은 / 는 ) 00001011( 11 )을 포함하고 있%s\n", num1, isTrue ? "다" : "지 않다" );

    return 0;
}