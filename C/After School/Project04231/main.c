#define _CRT_SECURE_NO_WARNIGNS
#include <stdio.h>

int main(void) {
	int i,wants;
	printf("ют╥б:");
	scanf("%d", &wants);

	for (i=1;i<10; i++) {
		printf("%d*%d=%d \n", wants, i, wants*i);
	}
	return 0;
}
//while (1) {
//	printf("* \n")
//	i++;
//	if (i>=11) {
//		break;
//	}
//}