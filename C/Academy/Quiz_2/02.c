#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <windows.h>

int main() {
    srand( time( 0 ) );

    int kor = 0, eng = 0, math = 0;
    int goodScore = 0, badScore;
    float arg = 0;
    kor = rand();

    printf( "우수 기준 점수를 입력하세요 >>> " );
    scanf( "%d", &goodScore );
    printf( "취약 기준 점수를 입력하세요 >>> " );
    scanf( "%d", &badScore );

    printf( "국어 점수는 %d점 입니다. ( %s )", kor );
    printf( "영어 점수는 %d점 입니다. ( %s )", eng );
    printf( "수학 점수는 %d점 입니다. ( %s )", math );

    printf( "평균 점수는 %.2f점 입니다. ( %s )합니다.", arg )

    system( "pause" );
    return 0;
}