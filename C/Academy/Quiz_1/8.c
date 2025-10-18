#include <stdio.h>

int main() {
    int num = 0;
    int isTrue = 0;
    

    printf( "정수를 입력하세요 >>> " );
    scanf( "%d", &num );

    if( num % 2 == 0 && num % 5 == 0 ) isTrue = 1;

    printf( "입력하신 정수[%d]( 은 / 는 ) 2의 배수이며 5의배수이다 ( %s )\n", num, isTrue ? "True" : "False" );


    return 0;
}