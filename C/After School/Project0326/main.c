#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a = 20;
	int age = 0;
	char name = 'Y';
	printf("%c님의 a의 값은 %d 입니다.", name, a);
	printf("나이 입력 : ");
	scanf("%d", &age);
	printf("입력하신 나이는 %d 입니다.", age);
	if (20 < age) {
		printf("성인이라 출입가능!");
	}  else {
		printf(" 출입금지! ");
	}

	return 0;
}