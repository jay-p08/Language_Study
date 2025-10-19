#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main2() {
	int computer, user, counter=0;
	srand(time(NULL));
	computer =rand() % 50+1;
	printf("정답 숫자 : %d \n", computer);
	while (1) {
		printf("숫자 얘기해! : ");
		scanf("%d", &user);
		counter++;
		if (user < computer) {
			printf("up!!!! \n");
		}
		else if (user > computer) {
			printf("down!!!! \n");
		}
		else if (user == computer) {
			printf("정답!!! \n");
			printf("%d회만에 정답 맟줬음", counter);
			break;
		}
	}

	return 0;
}