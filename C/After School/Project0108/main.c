#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mys.h"
int add(int, int);
int subt(int,int);
int mulp(int, int);
int main(int argc, char *argv[]) {
	int arg2 = atoi(argv[2]);
	int arg3 = atoi(argv[3]);
	printf("%s %d %d",argv[1],arg2,arg3);
		if (strcmp(argv[1], "add") == 0) {
			printf("\n%d", add(arg2, arg3));
		}
		else if (strcmp(argv[1], "subt") == 0) {
			printf("\n%d", subt(arg2, arg3));
		}
		else if (strcmp(argv[1], "mulp") == 0) {
			printf("\n%d", mulp(arg2, arg3));
		}
	//int a = 5, b = 3, c;
	//c = cal(a, b);
	//printf("\nResult = %d", c);
	/*c = cal2(a, b);
	printf("\nResult = %d", c);
	c = cal3(a, b);
	printf("\nResult = %d", c);
	c = cal4(a, b);
	printf("\nResult = %d", c);
	c = cal5(a, b);
	printf("\nResult = %d", c); */
	return 0;
}
//int add(int a, int b) {
//	return a + b;
//}
//int subt(int a, int b) {
//	return a - b;
//}
//int mulp(int a, int b) {
//	return a * b;
//}