#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int choice = 1;
	while (choice != 0) {
		printf("�޴� ����(1:�����, 2:���, 3:����, 0:����)-->");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("1�� \n");
			break;
		case 2:
			printf("2�� \n");
			break;
		case 3:
			printf("3�� \n");
			break;
		case 0:
			printf("0�� \n");
			break;
		}

	}

/*	int choice = 1;
	while (choice!=0) {
		printf("�޴� ����(1:�����, 2:���, 3:����, 0:����)-->");
		scanf("%d", &choice);
		//printf("���� �޴��� %d�Դϴ�.", choice);//
		if (choice == 1) {
			printf("�����, �ȳ�! \n");
		}
		else {
			if (choice == 2) {
				printf("���, �ȳ� \n");
			}
			else {
				if (choice == 3) {
					printf("����, �ȳ� \n");
				}
				else {
					if (choice == 0) {
						printf("����! \n");
					}
					else {
						printf("�� �� ����~ \n");
					}
				}
			}
		}
	}
*/
	

	return 0;
}