#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void codeExam() {
	char inputStr[30];
	printf("���ڿ� �Է�:");
	scanf("%s", &inputStr);
	for (int i = 0; inputStr[i] != '\0'; i++) {
			printf("%c \n", inputStr[i]);
	}
}
void charTrans() {
	char inputStr[30];
	printf("���ڿ� �Է�:");
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
	printf("���ڿ� �Է�:");
	scanf("%s", &inputStr);
	int i = 0;
	int num = 0;
	while (inputStr[i] != '\0') {
		i++;
		num++;
	}
	printf("%d�� \n", num);
}
void charReverse() {
	char inputStr[30];
	printf("���ڿ� �Է�:");
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
	printf("���ڿ� �Է�:");
	scanf("%s", &inputStr);
	char inputNum[30];
	printf("���ڿ� �Է�:");
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
		printf("---<����>---\n");
		printf("1.ù��° ���α׷� : ���ڿ��� �ѱ��ھ�\n");
		printf("2.�ι�° ���α׷� : �빮�ڸ� �ҹ��ڷ�, �ҹ��ڸ� �빮�ڷ� \n");
		printf("3.����° ���α׷� : �Է��� ���ڿ��� ���ڼ� ����ϱ� \n");
		printf("4.�׹�° ���α׷� : �Է��� ���ڿ��� �Ųٷ� ����ϱ� \n");
		printf("5.�ټ���° ���α׷� : �Է��� ���ڿ� �߿� �Է��� ���ڰ� �? \n");
		printf("6. ����\n");
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