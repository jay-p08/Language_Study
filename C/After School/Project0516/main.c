#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void avgFun(int st[]) {
	int total = 0;
	for (int i = 0; i < 5; i++) {
		total=total+st[i];
	}
	printf("�����: %d", total / 5);
}

int main() {
	int students[5];
	for(int i=0; i< 5 ; i++) {
		printf("%d�� �л� �����Է�: ", i + 1);
		scanf("%d", &students[i]);
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		printf("%d�� �л� ����: %d \n", i+1, students[i]);
	}
	avgFun(students);
	return 0;
}