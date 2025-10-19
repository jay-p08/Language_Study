#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char id[3][10];
char pw[3][10];

int idNum = 0;

void registerFun() {
	printf("가입 아이디 입력:");
	scanf("%s", id[idNum]);
	printf("가입 비번 입력:");
	scanf("%s", pw[idNum]);
	idNum++;
	if (idNum == 3) {
		printf("더이상 가입 불가능!");
	}
}
void view() {
	for (int i = 0; i < 3; i++) {
		printf("%d번 가입고객 아이디: %s \n", i, id[i]);
		printf("%d번 가입고객 비번: %s \n", i, pw[i]);
	}
}

int menu() {
	int choice = 0;
	while(1) {
		printf("*****[menu]*****\n");
		printf("1. 회원가입 \n");
		printf("2. 가입 조회  \n");
		printf("3. 로그인 \n");
		printf("4. 종료 \n");
		printf("***************\n");
		printf("메뉴선택 : ");
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
	printf("아이디 입력 : ");
	scanf("%s", inputId);
	printf( "패스워드 입력 : ");
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