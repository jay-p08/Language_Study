#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int jumsu[5];
	int view;
	char name[5][10];
	for (int i = 0; i < 5; i++) {
		printf("%d번 이름:", i + 1);
		scanf("%s", &name[i]);
		printf("%d번 점수:", i + 1);
		scanf("%d", &jumsu[i]);
		printf("-------------------\n");
	}
	for (int i = 0; i < 5; i++) {
		printf("%d번 %s 학생의 점수는 %d입니다. \n", i + 1, name[i], jumsu[i]);
	}
	printf("조회번호:");
	scanf("%d", &view);
	printf("%d 학생 이름:%s 점수 :%d ", view, name[view-1], jumsu[view - 1]);
	system("pause");


	//printf("%d번 이름: %s \n", i + 1, name[i]);

	//for (int i = 0; i < 5; i++) {
	//	printf("%d번점수: ", i+1);
	//	scanf("%d", &jumsu[i]);
	//	printf("%d번점수: %d \n", i+1 ,jumsu[i]);

	//}
	return 0;
}