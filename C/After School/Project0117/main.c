#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//int comp(const void* a, const void* b) {
//	return (*(int*)b - *(int*)a);  // 내림차순: 큰 수가 앞에 오도록
//}
//
//int main() {
//	int a;
//	int b[13] = {0};
//	int n = sizeof(b) / sizeof(b[0]);
//	srand(time(NULL));
//	for (int i = 0; i < 1000000; i++) {
//		int dice1 = rand() % 6 + 1;
//		int	dice2 = rand() % 6 + 1;
//		a = dice1 + dice2;
//		b[a]++;
//	}
//	for (int i = 2; i <= 12; i++) {
//		printf("b[%d] = %d %f%%\n", i, b[i], (double)b[i] / 1000000 * 100);
//	}
//
//	return 0;
//}
int main() {
	int a;
	printf("2진수 입력:");
	scanf("%d", &a);
	int b = strtol(a, NULL, 2);
	printf("2진수 %d를 10진수로 -> %d", a, b);

	return 0;
}