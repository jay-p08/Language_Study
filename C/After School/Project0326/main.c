#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a = 20;
	int age = 0;
	char name = 'Y';
	printf("%c���� a�� ���� %d �Դϴ�.", name, a);
	printf("���� �Է� : ");
	scanf("%d", &age);
	printf("�Է��Ͻ� ���̴� %d �Դϴ�.", age);
	if (20 < age) {
		printf("�����̶� ���԰���!");
	}  else {
		printf(" ���Ա���! ");
	}

	return 0;
}