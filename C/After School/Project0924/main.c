#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//void upper_char(char*, char*);
void div(double*, int*);
int main() {
	//char a;
	//char b;
	//printf("�Է�:");
	//scanf("%c %c", &a, &b);
	//upper_char(&a,&b);

	//printf("�빮�� : %c \n", a);
	//printf("�빮�� : %c \n", b);
	double d;
	int b;
	printf("�Է�:");
	scanf("%lf", &d);
	div(&d,&b);

	printf("���� ��: %d \n�Ǽ� ��: %lf", b, d);

	return 0;
}

//void upper_char(char *a, char *b) {
//	*a = *a - 32;
//	*b = *b - 32;
//}
void div(double *d, int *b) {
	*b = *d;
	*d = *d - *b;
}