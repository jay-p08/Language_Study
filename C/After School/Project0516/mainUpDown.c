#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main2() {
	int computer, user, counter=0;
	srand(time(NULL));
	computer =rand() % 50+1;
	printf("���� ���� : %d \n", computer);
	while (1) {
		printf("���� �����! : ");
		scanf("%d", &user);
		counter++;
		if (user < computer) {
			printf("up!!!! \n");
		}
		else if (user > computer) {
			printf("down!!!! \n");
		}
		else if (user == computer) {
			printf("����!!! \n");
			printf("%dȸ���� ���� ������", counter);
			break;
		}
	}

	return 0;
}