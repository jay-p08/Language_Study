#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a[7];
	int b = 0;
	int arr_size = sizeof(a) / sizeof(int);
	for (int i = 0; i < arr_size; i++) {
		printf("�Է�:");
		scanf("%d", &a[i]);
		b += a[i];
	}
	printf("��: %d", b);
		return 0;
}