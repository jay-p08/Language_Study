#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
/*
	int  math ;
	printf("���� ���� �Է� : ");
	scanf("%d", &math);
	// ���м����� 60�� �����̸� ���հ��Դϴ�.
	if (math <= 60) { //���ǽ�: �� or ���� �����
		printf("���հ�!");
	} 
	else {
		printf("�հ�!");
	}
	printf("���� ��!");

*/

	int num;
	printf("���� �Է� : ");
	scanf("%d", &num);  //�Է��� ���ڰ� ����, ����, ��� ���� ���
	if (num>0) {
		printf(" ���! ");
	}
	else {
		if (num == 0) {
			printf(" ����! ");
		}
		else {
			printf(" ����! ");
		}
	}
	
	while(num < 100) {
		printf(" ****** \n ");
		num = num + 1;
	}

	return 0;
}