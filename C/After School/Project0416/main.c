#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void changeMoney() {
	int price, c5000, c1000, c500, c100;
	int user, change;
	printf("물건값을 입력  :");
	scanf("%d", &price);
	printf("손님이 낸 돈 :");
	scanf("%d", &user);
	change = user - price;
	c5000 = change / 5000;
	change = change % 5000;
	c1000 = change / 1000;
	change = change % 1000;
	c500 = change / 500;
	change = change % 500;
	c100 = change / 100;
	change = change % 100;
	printf("물건값은 %d이고, 낸 돈은 %d은 \n 오천원권은 %d장, 천원권은 %d장, 오백원권은 %d장, 백원권은 %d장, 나머지는 %d", price, user, c5000, c1000, c500, c100, change);
}



int main() {
	changeMoney();
	printf("main 함수 호출");

	//int id, pwd;
	//printf("아이디/암호를 숫자4글자 입력:\n");
	//printf("아이디: ____\b\b\b\b");
	//scanf("%d", &id);
	//printf("비밀번호: ____\b\b\b\b");
	//scanf("%d", &pwd);
	//if (id == 1234 && pwd == 5678) {
	//	printf("로그인 성공! 윤건님, 환영!!!");
	//}
	//else {
	//	printf("로그인 실패! 아이디 및 비번 확인!\a");
	//}
	//printf("당신의 아이디는 %d이고, \n 암호는 %d", id, pwd);
	//printf("\a 나는 \n \t\"윤건\" \t입니다!\b5");
	
	return 0;
}