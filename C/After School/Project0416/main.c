#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void changeMoney() {
	int price, c5000, c1000, c500, c100;
	int user, change;
	printf("���ǰ��� �Է�  :");
	scanf("%d", &price);
	printf("�մ��� �� �� :");
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
	printf("���ǰ��� %d�̰�, �� ���� %d�� \n ��õ������ %d��, õ������ %d��, ��������� %d��, ������� %d��, �������� %d", price, user, c5000, c1000, c500, c100, change);
}



int main() {
	changeMoney();
	printf("main �Լ� ȣ��");

	//int id, pwd;
	//printf("���̵�/��ȣ�� ����4���� �Է�:\n");
	//printf("���̵�: ____\b\b\b\b");
	//scanf("%d", &id);
	//printf("��й�ȣ: ____\b\b\b\b");
	//scanf("%d", &pwd);
	//if (id == 1234 && pwd == 5678) {
	//	printf("�α��� ����! ���Ǵ�, ȯ��!!!");
	//}
	//else {
	//	printf("�α��� ����! ���̵� �� ��� Ȯ��!\a");
	//}
	//printf("����� ���̵�� %d�̰�, \n ��ȣ�� %d", id, pwd);
	//printf("\a ���� \n \t\"����\" \t�Դϴ�!\b5");
	
	return 0;
}