#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int jumsu[5];
	int view;
	char name[5][10];
	for (int i = 0; i < 5; i++) {
		printf("%d�� �̸�:", i + 1);
		scanf("%s", &name[i]);
		printf("%d�� ����:", i + 1);
		scanf("%d", &jumsu[i]);
		printf("-------------------\n");
	}
	for (int i = 0; i < 5; i++) {
		printf("%d�� %s �л��� ������ %d�Դϴ�. \n", i + 1, name[i], jumsu[i]);
	}
	printf("��ȸ��ȣ:");
	scanf("%d", &view);
	printf("%d �л� �̸�:%s ���� :%d ", view, name[view-1], jumsu[view - 1]);
	system("pause");


	//printf("%d�� �̸�: %s \n", i + 1, name[i]);

	//for (int i = 0; i < 5; i++) {
	//	printf("%d������: ", i+1);
	//	scanf("%d", &jumsu[i]);
	//	printf("%d������: %d \n", i+1 ,jumsu[i]);

	//}
	return 0;
}