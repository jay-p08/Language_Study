#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int choice = 1;
	while (choice != 0) {
		printf("메뉴 선택(1:자장면, 2:라면, 3:라볶이, 0:종료)-->");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("1번 \n");
			break;
		case 2:
			printf("2번 \n");
			break;
		case 3:
			printf("3번 \n");
			break;
		case 0:
			printf("0번 \n");
			break;
		}

	}

/*	int choice = 1;
	while (choice!=0) {
		printf("메뉴 선택(1:자장면, 2:라면, 3:라볶이, 0:종료)-->");
		scanf("%d", &choice);
		//printf("선택 메뉴는 %d입니다.", choice);//
		if (choice == 1) {
			printf("자장면, 냠냠! \n");
		}
		else {
			if (choice == 2) {
				printf("라면, 냠냠 \n");
			}
			else {
				if (choice == 3) {
					printf("라볶이, 냠냠 \n");
				}
				else {
					if (choice == 0) {
						printf("종료! \n");
					}
					else {
						printf("말 좀 들어라~ \n");
					}
				}
			}
		}
	}
*/
	

	return 0;
}