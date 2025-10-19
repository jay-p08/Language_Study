#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void avgFun(int st[]) {
	int total = 0;
	for (int i = 0; i < 5; i++) {
		total=total+st[i];
	}
	printf("반평균: %d", total / 5);
}

int main() {
	int students[5];
	for(int i=0; i< 5 ; i++) {
		printf("%d번 학생 성적입력: ", i + 1);
		scanf("%d", &students[i]);
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		printf("%d번 학생 성적: %d \n", i+1, students[i]);
	}
	avgFun(students);
	return 0;
}