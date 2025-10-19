#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sub(a);
//int g;
//static int sg; //다른 파일에서 사용할 수 없음.
int main() {
	int a[5];
	//int ma = 5;
	//g = 3;
	//printf("%d \n", sg);
	//sub(); sub();
	//printf("%d \n", g);
	for (int i = 0; i < 5; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 5; i++) {
		printf("%d \t", a[i]);
	}
	sub(a);
	return 0;
}
void sub(int a[]) {
	//int a = 1;
	//static int b = 1;
	//printf("%d \n", sg);
	//a++; b++;
	//printf("%d \n", a); 	printf("%d \n", b);
	//g = 8;
		for (int j = 4; j >= 0; j--) {
			printf("%d \t", a[j]);
	}
}