#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//���� 'k'�� ���� ch�� �����ϰ� ch�� �ּҸ� ���� pch�� �����ϰ� �������ڸ� ����ϰ� pch�� �̿��Ͽ�
//���ڸ� 't'�� ������ �� ch������ ���

//�Ǽ� 2�� �����ϰ� 2���� �Ǽ��� �� ������ ���� ������ ������ �̿��Ͽ� �����ϰ� ����� ���

int main() {
	//������ ����
	//int a = 5, *p;
	//p = &a;
	//printf(" a: %d  *p: %d \n", a, *p);
	//printf(" a�� �ּ�: %p  p ���� ��: %p ", &a, p);

	//char ch = 'k'; char *pch;
	//pch = &ch;
	//printf("���� %c   ���� %c \n", ch, *pch);
	//*pch = 't';
	//printf("���� ���� %c", ch);
	
	double a = 1.5, b = 2.5;
	double* aa = &a, *bb = &b;
	double result = a+b;
	printf("%tf + %tf = %tf", a, b, result);

	return 0;
}