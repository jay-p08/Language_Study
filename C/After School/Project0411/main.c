#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a = 0;
	int b;
	++a;
	while (a<100) {
		printf("���� a�� ����: %d \n", a);
		b = ++a;
		printf("���� b�� ����: %d \n", b);
		printf("----------------- \n");
	}
	printf("��!");

	//int num;
	//int num2;
	//printf("���� �Է� :");
	//scanf("%d", &num);
	//num2 = num % 2;
	//if (num2 == 0) {
	//	printf("%d ���ڴ� ¦�� ");
	//}
	//else {
	//	printf("%d ���ڴ� Ȧ�� ");
	//}
//	float weigth;
//	float heigth;
//	float result;
//	printf("Ű �Է� : ");
//	scanf("%f", &heigth);
//	printf("������ �Է� : ");
//	scanf("%f", &weigth);
//	result = weigth / (heigth * heigth);
//	printf("���� Ű�� %f m�̰�, �����Դ� %f kg \n", heigth, heigth);
//	printf("�׷��� ���� bmi������ %f", result);
//	if (result>=25.0) {
//		printf("�ʴ� ��! ���!");
//	}
//	else {
//		if (result>=23.0) {
//			printf("�ʴ� ��ü��!");
//		} 
//		else {
//			if (result>=18.5) {
//				printf("�ʴ� ����!");
//			}
//			else {
//				printf("�ʴ� ��ü��!");
//			}
//
//		}
//	
//	}



	return 0;
}