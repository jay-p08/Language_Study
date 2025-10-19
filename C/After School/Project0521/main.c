#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int jumsu[5]; //전역변수
int menuChoice() {
	int choice = 0; //지역변수
	while (1) {
		printf("1. 점수 입력 \n");
		printf("2. 점수 조회 \n");
		printf("3. 전체 평균 조회 \n");
		printf("4. 최고 점수 조회 \n");
		printf("5. 종료 \n");
		scanf("%d", &choice);
		if (0 < choice && 6 > choice) {
			break;
		}
	}
	return choice;
}
void inputJumsu() {
	for (int i = 0; i < 5; i++) {
		printf("%d번 학생의 점수 : ", i);
		scanf("%d", &jumsu[i]);

	}
}
void viewJumsu() {
	for (int i = 0; i < 5; i++) {
		printf("%d번 학생의 점수 : %d \n", i, jumsu[i]);
	}
}
void averageJumsu() {
	int total = 0;
	float avg = 0.0;
	for (int i = 0; i < 6; i++) {
		total = total + jumsu[i];
	}
	avg = total / 5.0;
	printf("전체평균: %f \n", avg);
}
void maxJumsu() {
	int max = 0;
	for (int i = 0; i < 5; i++) {
		if (max < jumsu[i]) {
		max = jumsu[i];
		}
	}
	printf("최고점수: %d \n", max);
}
int main() {
	int m = 0;
	char name[2][10];

	printf("1번 이름입력:");
	scanf("%s", &name[0]);
	printf("1번 이름: %s \n", name[0]);

	printf("2번 이름입력:");
	scanf("%s", &name[1]);
	printf("2번 이름: %s \n", name[1]);
	//while (1) {
	//	m = menuChoice();
	//	switch (m) {
	//	case 1:
	//		inputJumsu();
	//		break;
	//	case 2:
	//		viewJumsu();
	//		break;
	//	case 3:
	//		averageJumsu();
	//		break;
	//	case 4:
	//		maxJumsu();
	//		break;
	//	case 5:
	//		return 0;
	//	}
	//}

}