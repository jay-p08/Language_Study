#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char id[3][10];
char pw[3][10];

int idNum = 0;

void registerFun() {
	printf("���� ���̵� �Է�:");
	scanf("%s", id[idNum]);
	printf("���� ��� �Է�:");
	scanf("%s", pw[idNum]);
	idNum++;
	if (idNum == 3) {
		printf("���̻� ���� �Ұ���!");
	}
}
void view() {
	for (int i = 0; i < 3; i++) {
		printf("%d�� ���԰� ���̵�: %s \n", i, id[i]);
		printf("%d�� ���԰� ���: %s \n", i, pw[i]);
	}
}

int menu() {
	int choice = 0;
	while(1) {
		printf("*****[menu]*****\n");
		printf("1. ȸ������ \n");
		printf("2. ���� ��ȸ  \n");
		printf("3. �α��� \n");
		printf("4. ���� \n");
		printf("***************\n");
		printf("�޴����� : ");
		scanf("%d", &choice);
		if (choice >= 1 && choice < 5) {
			break;
		}
	}
	return choice
}

void login() {
	char inputId[10];
	char inputPw[10];
	int checkNum;
	printf("���̵� �Է� : ");
	scanf("%s", inputId);
	printf( "�н����� �Է� : ");
	scanf("%s", &inputPw);
	for (int i = 0; i < 3; i++) {
		if (id[i] == inputId) {
			checkNum = i;
			break;
		} 
	}
	if (pw[checkNum] == inputPw) {

	}
	else {

	}
}

int main() {
	int m;
	while (1) {
		m=menu();
		switch (m) {
		case 1 : 
			registerFun();
			break;
		case 2 : 
			view();
			break;
		case 3 :
			login();
			break;
		case 4 : 
			return 0;
		}
	}
	return 0;

}