#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int jumsu[5]; //��������
int menuChoice() {
	int choice = 0; //��������
	while (1) {
		printf("1. ���� �Է� \n");
		printf("2. ���� ��ȸ \n");
		printf("3. ��ü ��� ��ȸ \n");
		printf("4. �ְ� ���� ��ȸ \n");
		printf("5. ���� \n");
		scanf("%d", &choice);
		if (0 < choice && 6 > choice) {
			break;
		}
	}
	return choice;
}
void inputJumsu() {
	for (int i = 0; i < 5; i++) {
		printf("%d�� �л��� ���� : ", i);
		scanf("%d", &jumsu[i]);

	}
}
void viewJumsu() {
	for (int i = 0; i < 5; i++) {
		printf("%d�� �л��� ���� : %d \n", i, jumsu[i]);
	}
}
void averageJumsu() {
	int total = 0;
	float avg = 0.0;
	for (int i = 0; i < 6; i++) {
		total = total + jumsu[i];
	}
	avg = total / 5.0;
	printf("��ü���: %f \n", avg);
}
void maxJumsu() {
	int max = 0;
	for (int i = 0; i < 5; i++) {
		if (max < jumsu[i]) {
		max = jumsu[i];
		}
	}
	printf("�ְ�����: %d \n", max);
}
int main() {
	int m = 0;
	char name[2][10];

	printf("1�� �̸��Է�:");
	scanf("%s", &name[0]);
	printf("1�� �̸�: %s \n", name[0]);

	printf("2�� �̸��Է�:");
	scanf("%s", &name[1]);
	printf("2�� �̸�: %s \n", name[1]);
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