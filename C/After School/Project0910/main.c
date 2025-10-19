#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//문자 'k'를 변수 ch에 저장하고 ch의 주소를 변수 pch에 보관하고 각각문자를 출력하고 pch를 이용하여
//문자를 't'로 변경한 후 ch변수를 출력

//실수 2개 저장하고 2개의 실수의 합 변수에 저장 포인터 변수를 이용하여 연산하고 결과를 출력

int main() {
	//포인터 정리
	//int a = 5, *p;
	//p = &a;
	//printf(" a: %d  *p: %d \n", a, *p);
	//printf(" a의 주소: %p  p 보관 값: %p ", &a, p);

	//char ch = 'k'; char *pch;
	//pch = &ch;
	//printf("문자 %c   문자 %c \n", ch, *pch);
	//*pch = 't';
	//printf("변경 문자 %c", ch);
	
	double a = 1.5, b = 2.5;
	double* aa = &a, *bb = &b;
	double result = a+b;
	printf("%tf + %tf = %tf", a, b, result);

	return 0;
}