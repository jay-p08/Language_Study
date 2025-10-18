#include <stdio.h>

int main() {
    char name[50];
    int age = 0;
    float w = 0, h = 0;

    printf( "이름을 입력하세요 : " );
    scanf( " %s", name );
    printf( "나이를 입력하세요 : " );
    scanf( " %d", &age );
    printf( "키와 몸무게를 입력하세요( 키 몸무게 ) : " );
    scanf( " %f %f", &h, &w );
    printf( "%s님 반갑습니다.\n", name );
    printf( "%s님의 나이는 %d세이고, 키 %.1fCm, 몸무게 %.2fKg입니다.\n", name, age, h, w );

    return 0;
}