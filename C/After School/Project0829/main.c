#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a[5][2];
	int b = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("��ȣ�Է�:");
			scanf("%d", &a[i]);
			printf("����⵵:");
			scanf("%d", &a[j]);
			b = 2024 - a[i][j] + 1;

			printf("��ȣ: %d \n", a[i][j]);
			printf("����⵵: %d \n", a[i][j]);
			printf("����:%d \n", b);
		}
	}
	return 0;
}