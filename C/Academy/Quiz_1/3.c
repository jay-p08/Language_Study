#include <stdio.h>

int main() {
    int num1 = 0;
    int num2 = 0;

    printf( "기준 정수를 입력하세요 >>> " );
    scanf( "%d", &num1 );
    printf( "연산 정수를 입력하세요 >>> " );
    scanf( "%d", &num2 );

    if ( num2 >= 10 ) {
        printf( "%d << %d = %d\n", num1, num2, num1 << num2 );
    } // if
    else {
        printf( "%d >> %d = %d\n", num1, num2, num1 >> num2 );
    } // else
    

    return 0;
}