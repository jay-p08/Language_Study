#define _CRT_SECURE_NO_WARNINGS
#include "mainh.h"

int main() {
	int a, totalcount = 0;
	BOOK* mybook;
	//FILE* fp = fopen("save.txt", "r+"); //����Ʈ���� �������� �������ڰ˻�
	mybook = (BOOK *)calloc(1,sizeof(BOOK));
	if (mybook == NULL) {
		printf("�޸��Ҵ� ����");
	}
	while (1) {
		puts("\n-------�޴�-------");
		puts("1.�����Է�");
		puts("2.�������");
		puts("3.�����˻�");
		puts("4.��������,����");
		puts("5.����");
		scanf("%d", &a);
		switch (a) {
		case 1: totalcount = BookInput(mybook, totalcount);	break;
		case 2: BookOutput(mybook, totalcount); break;
		case 3: BookSearch(mybook, totalcount); break;
		case 4: totalcount = BookDelRev(mybook, totalcount); break;
		case 5: return 0;
		default: puts("�޴� �ٽ� �������ּ���.");
		}
	}
	return 0;
}