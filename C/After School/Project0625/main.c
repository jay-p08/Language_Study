#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //srand(), rand()
#include <time.h> //time

int main() {
	int student[5];
	for (int i = 0; i < 5; i++) {
		printf("%d�� �л� ����:", i + 1);
		scanf("%d", &student[i]);
		if (student[i] < 0 || student[i] > 100) {
			printf("����!");
			return 0;
		}
	}
	int total = 0;
	for (int i = 0; i < 5; i++) {
		total = total + student[i];
	}
	printf("�����: %d \n", total / 5);
	for (int j = 0; j < 5; j++) {
		if (total <= student[j]/5) {
			printf("%d�� ���� \n", j + 1);
		}
		else {
			printf("%d�� ���� \n", j + 1);
		}
	}
	return 0;
}