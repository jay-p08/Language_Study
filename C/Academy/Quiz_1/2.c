#include <stdio.h>

int main() {
    int w = 0;
    int h = 0;

    printf( "사각형의 가로길이 >>> " );
    scanf( "%d", &w );
    printf( "사각형의 세로길이 >>> " );
    scanf( "%d", &h );

    printf( "가로길이 %d..., 세로길이 %d... 인 사각형의 면적은 %d입니다.\n", w, h, w * h );

    return 0;
}