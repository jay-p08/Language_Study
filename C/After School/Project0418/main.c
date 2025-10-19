#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char name = 'g'; //전역변수
int result = 0;

//int add(int a, int b) {
//	char name = 'l';
//	printf("name값: %d", name);
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
	printf("계산식을 입력: ex. 2 + 3 -->");
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
		printf("사칙연산자만 입력!");
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

	printf("결과값은 : %d", result);
	return 0;
}