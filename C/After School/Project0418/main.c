#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char name = 'g'; //��������
int result = 0;

//int add(int a, int b) {
//	char name = 'l';
//	printf("name��: %d", name);
//	return a + b;
//}
void add(int a, int b) {
	result = a + b;
}

void sub(int a, int b) {
	result = a - b;
}

void mul(int a, int b) {
	result = a * b;
}
void div(int a, int b) {
	result = a / b;
}

int main(void) {
	int num1, num2, result;
	char op;
	printf("������ �Է�: ex. 2 + 3 -->");
	scanf("%d %c %d", &num1, &op, &num2);
	
	switch (op) {
	case'+':
		 add(num1, num2);
		break;
	case'-':
		sub(num1, num2);
		break;
	case'*':
		mul(num1, num2);
		break;
	case'/':
		div(num1, num2);
		break;
	default:
		printf("��Ģ�����ڸ� �Է�!");
	}

	//if (op == '+') {
	//	result = num1 + num2;
	//}
	//else {
	//	if (op == '-') {
	//		result = num1 - num2;
	//	}
	//	else {
	//		if (op == '*') {
	//			result = num1 * num2;
	//		}
	//		else {
	//			result = num1 / num2;
	//		}
	//	}
	//}

	printf("������� : %d", result);
	return 0;
}