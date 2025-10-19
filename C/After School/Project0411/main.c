#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a = 0;
	int b;
	++a;
	while (a<100) {
		printf("현재 a의 값은: %d \n", a);
		b = ++a;
		printf("현재 b의 값은: %d \n", b);
		printf("----------------- \n");
	}
	printf("끝!");

	//int num;
	//int num2;
	//printf("숫자 입력 :");
	//scanf("%d", &num);
	//num2 = num % 2;
	//if (num2 == 0) {
	//	printf("%d 숫자는 짝수 ");
	//}
	//else {
	//	printf("%d 숫자는 홀수 ");
	//}
//	float weigth;
//	float heigth;
//	float result;
//	printf("키 입력 : ");
//	scanf("%f", &heigth);
//	printf("몸무게 입력 : ");
//	scanf("%f", &weigth);
//	result = weigth / (heigth * heigth);
//	printf("너의 키는 %f m이고, 몸무게는 %f kg \n", heigth, heigth);
//	printf("그래서 너의 bmi지수는 %f", result);
//	if (result>=25.0) {
//		printf("너는 비만! 살뺴!");
//	}
//	else {
//		if (result>=23.0) {
//			printf("너는 과체중!");
//		} 
//		else {
//			if (result>=18.5) {
//				printf("너는 정상!");
//			}
//			else {
//				printf("너는 저체중!");
//			}
//
//		}
//	
//	}



	return 0;
}