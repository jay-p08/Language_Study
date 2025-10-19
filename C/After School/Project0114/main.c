#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void sub(int**);
int main() {
	int n = 3, *pi, a[10];
	pi = (int*)malloc(sizeof(int) * n);
	pi[0] = 3; pi[1] = 6;
	printf("main: %d %d \n", pi[0], pi[1]);
	printf("주소: %p\n", pi);
	sub(&pi);
	printf("주소: %p\n", pi);
	printf("메인(서브콜): %d %d %d\n", pi[0], pi[1], pi[2]);
	return 0;
}
void sub(int** pi) {
	int n = 50000;
	*pi = (int)realloc(*pi, sizeof(int) * n);
	printf("sub: %d %d\n", pi[0], pi[1]);
	pi[0] = 13; pi[1] = 15; pi[2] = 20;
	printf("바뀐: %d %d %d\n", pi[0], pi[1], pi[2]);

}