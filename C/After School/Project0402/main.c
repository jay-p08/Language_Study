#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
/*
	int  math ;
	printf("수학 성적 입력 : ");
	scanf("%d", &math);
	// 수학성적이 60점 이하이면 불합격입니다.
	if (math <= 60) { //조건식: 참 or 거짓 결과값
		printf("불합격!");
	} 
	else {
		printf("합격!");
	}
	printf("판정 끝!");

*/

	int num;
	printf("숫자 입력 : ");
	scanf("%d", &num);  //입력한 숫자가 음수, 제로, 양수 판정 결과
	if (num>0) {
		printf(" 양수! ");
	}
	else {
		if (num == 0) {
			printf(" 제로! ");
		}
		else {
			printf(" 음수! ");
		}
	}
	
	while(num < 100) {
		printf(" ****** \n ");
		num = num + 1;
	}

	return 0;
}