#include <stdio.h>

int main() {
    int home = 0;

    printf( "당신의 집은 몇평인가요 >>> " );
    scanf( "%d", &home );

    printf( "%d평은 %.1f제곱미터입니다.\n", home, 3.305 * home );    

    return 0;
}