#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a[5][2];
	int b = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("번호입력:");
			scanf("%d", &a[i]);
			printf("출생년도:");
			scanf("%d", &a[j]);
			b = 2024 - a[i][j] + 1;

			printf("번호: %d \n", a[i][j]);
			printf("출생년도: %d \n", a[i][j]);
			printf("나이:%d \n", b);
		}
	}
	return 0;
}