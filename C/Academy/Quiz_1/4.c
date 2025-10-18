#include <stdio.h>

int main() {
    int kor = 0;
    int eng = 0;
    int math = 0;
    int sum = 0;
    float age = 0;

    printf( "국어, 영어, 수학 점수를 입력하세요( 국어, 영어, 수학 ) >>> " );
    scanf( "%d %d %d", &kor, &eng, &math );
    sum = kor + eng + math;
    age = sum / 3;
    
    printf( "국, 영, 수 세과목의 총점은 [%d]점이고, 평균은 [%.2f]점 입니다.\n", sum, age );    

    return 0;
}