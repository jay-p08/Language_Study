#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void codeExam() {
	char inputStr[30];
	printf("문자열 입력:");
	scanf("%s", &inputStr);
	for (int i = 0; inputStr[i] != '\0'; i++) {
			printf("%c \n", inputStr[i]);
	}
}
void charTrans() {
	char inputStr[30];
	printf("문자열 입력:");
	scanf("%s", &inputStr);
	for (int i = 0; inputStr[i] != '\0'; i++) {
		if (inputStr[i] >=65 && inputStr[i] <= 90) {
			inputStr[i] = inputStr[i] + 32;
		}
		else if (inputStr[i] >= 97 && inputStr[i] <= 122) {
			inputStr[i] = inputStr[i] - 32;
		}
	}
	printf("%s \n", inputStr);
}
void charLength() {
	char inputStr[30];
	printf("문자열 입력:");
	scanf("%s", &inputStr);
	int i = 0;
	int num = 0;
	while (inputStr[i] != '\0') {
		i++;
		num++;
	}
	printf("%d개 \n", num);
}
void charReverse() {
	char inputStr[30];
	printf("문자열 입력:");
	scanf("%s", &inputStr);
	int i = 0;
	while (inputStr[i] != '\0') {
		i++;
	}
	while (i != 0) {
		printf("%c", inputStr[i - 1]);
		i--;
	}
	printf("\n");
}
void charnum() {
	char inputStr[30];
	char inputNum[30];
	printf("문자열 입력:");
	scanf("%s", &inputStr);
	char inputNum[30];
	printf("문자열 입력:");
	scanf("%c", &inputNum);
	int i = 0;
	int my = 0;
	while (inputStr[i] != '\0') {
		i++;
		my++;
	}
	while (inputNum[i] != '\0') {
		i++;
		my++;
	}
	printf("%c \n", i);
}

int main() {
	int choice;
	while (1) {
		printf("---<선택>---\n");
		printf("1.첫번째 프로그램 : 문자열을 한글자씩\n");
		printf("2.두번째 프로그램 : 대문자를 소문자로, 소문자를 대문자로 \n");
		printf("3.세번째 프로그램 : 입력한 문자열의 글자수 출력하기 \n");
		printf("4.네번째 프로그램 : 입력한 문자열을 거꾸로 출력하기 \n");
		printf("5.다섯번째 프로그램 : 입력한 문자열 중에 입력한 문자가 몇개? \n");
		printf("6. 종료\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			codeExam();
			break;
		case 2:
			charTrans();
			break;
		case 3:
			charLength();
			break;
		case 4:
			charReverse();
			break;
		case 5:
			charnum();
			break;
		case 6:
			return 0;
		}

	}

	return 0;
}