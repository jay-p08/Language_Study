#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //srand(), rand()....
#include <time.h> //time(),....
int userInput() {
	int num1 = 0; //����: 1, ����: 2, ��: 3
	printf("���� ���� �Է�!: ");
	scanf("%d", &num1);
	return num1;
}
int aiInput() {
	srand(time(NULL));
	int num2 = (rand()%3)+1;
	return num2;
}
int main(void) {
	int n1=userInput();
	int n2 = aiInput();
	int result = n1 - n2;
	if (result == 0) {
		printf("��: %d, ��: %d ==>����:���!", n1, n2);
	}
	else if (result==-1 || result == 2) {
		printf("��: %d, ��: %d ==>����:�� �¸�!", n1, n2);
	}
	else if (result==-2 || result == 1) {
		printf("��: %d, ��: %d ==>����:�� �¸�!", n1, n2);
	}

	return 0;
}