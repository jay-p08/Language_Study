#define _CRT_SECURE_NO_WARNINGS
#include "mainh.h"

int main() {
	int a, totalcount = 0;
	BOOK* mybook;
	//FILE* fp = fopen("save.txt", "r+"); //베스트셀러 수정삭제 제목저자검색
	mybook = (BOOK *)calloc(1,sizeof(BOOK));
	if (mybook == NULL) {
		printf("메모리할당 실패");
	}
	while (1) {
		puts("\n-------메뉴-------");
		puts("1.도서입력");
		puts("2.도서출력");
		puts("3.도서검색");
		puts("4.도서수정,삭제");
		puts("5.종료");
		scanf("%d", &a);
		switch (a) {
		case 1: totalcount = BookInput(mybook, totalcount);	break;
		case 2: BookOutput(mybook, totalcount); break;
		case 3: BookSearch(mybook, totalcount); break;
		case 4: totalcount = BookDelRev(mybook, totalcount); break;
		case 5: return 0;
		default: puts("메뉴 다시 선택해주세요.");
		}
	}
	return 0;
}