#define _CRT_SECURE_NO_WARNINGS
#include "mainh.h"

int BookInput(BOOK* mb, int cnt) {
	FILE* fp = fopen("save.txt", "a+ "); //베스트셀러 수정삭제 제목저자검색
	int leng;
	int yn;
	while (1) {
		getchar();
		printf("제목:");
		gets(mb[cnt].bookname);
		printf("저자:");
		gets(mb[cnt].bookauthor);
		printf("가격:");
		scanf("%d", &mb[cnt].bookprice);
		printf("판매 수량:");
		scanf("%d", &mb[cnt].bookSA);
		getchar();
		while (1) {
			printf("책 코드:");
			gets(mb[cnt].bookcode);
			if (strlen(mb[cnt].bookcode) == 8) {
				leng = strspn(mb[cnt].bookcode, "0123456789-");
				if (leng == 8 && leng != 0) break;
			}
			printf("코드를 다시확인하시오.\n");
		}
		fprintf(fp, "%s %s %d %d %s\n", mb[cnt].bookname, mb[cnt].bookauthor, mb[cnt].bookprice,
			mb[cnt].bookSA, mb[cnt].bookcode);
		cnt++;
		printf("다시 입력하시겠습니까?1.Y/2.N : ");
		scanf("%d", &yn);
		if (yn == 1) {
			printf("계속작성!\n");
		}
		if (yn == 2) break;
		else if (yn != 1 && yn != 2) {
			printf("1,2둘중하나선택!\n");
			break;
		}
	}
	mb = (BOOK*)realloc(mb, cnt * sizeof(BOOK));
	return cnt;
}

void BookOutput(BOOK* mb, int cnt) {
	FILE* fp = fopen("save.txt", "r"); //베스트셀러 수정삭제 제목저자검색
	fscanf(fp, "%s %s %d %d %s", mb[cnt].bookname, mb[cnt].bookauthor, mb[cnt].bookprice,
		mb[cnt].bookSA, mb[cnt].bookcode);
	int n;
	char y[5];
	int bo;
	y[4] = '\0';
	puts("1.전체출력 | 2.출판년도출력 | 3.베스트셀러");
	scanf("%d", &n);
	switch (n) {
	case 1:
		printf("\n------------------");
		printf("\n제목 | 저자 | 가격 | 수량 | 코드 |");
		for (int i = 0; i < cnt; i++) {
			printf("%d번 책", i + 1);
			printf("\n%s | %s | %d | %d | %s |\n", mb[i].bookname, mb[i].bookauthor, mb[i].bookprice, mb[i].bookSA, mb[i].bookcode);
			if ((i + 1) % 10 == 0 && i != cnt - 1) {
				printf("아무키나 눌러 다음페이지로");
				//fgetc(stdin);
				getch();
				printf("\n------------------");
				printf("\n제목 | 저자 | 가격 | 수량 | 코드 |");
			}
		}
		break;
	case 2:
		getchar();
		printf("출판년도입력:");
		gets(y);
		int con = 0;
		char sa[9];
		printf("\n------------------");
		printf("\n출판년도\n%s", y);
		printf("\n제목 | 저자 | 가격 | 수량 |");
		for (int i = 0; i < cnt; i++) {
			strcpy(sa, mb[i].bookcode);
			if (strncmp(sa, y, 4) == 0) {
				printf("\n%s | %s | %d | %d |\n", mb[i].bookname, mb[i].bookauthor, mb[i].bookprice,
					mb[i].bookSA);
				con++;
			}
			else if (con == 0) {
				printf("해당 년도에 관한 책이 없습니다.");
			}
		}
		break;
	case 3:
		printf("베스트셀러순위정하기:");
		scanf("%d", &bo);
		for (int i = 0; i < cnt - 1; i++) {
			int maxIndex = i;
			for (int j = i + 1; j < cnt; j++) {
				if (mb[j].bookSA > mb[maxIndex].bookSA) {  // 내림차순 비교
					maxIndex = j;
				}
			}
			struct book temp = mb[i];
			mb[i] = mb[maxIndex];
			mb[maxIndex] = temp;
		}
		printf("\n------------------");
		printf("\n베스트셀러 TOP%d", bo);
		printf("\n제목 | 저자 | 가격 | 수량 |");
		for (int i = 0; i < bo && i < cnt; i++) {
			printf("\n%d위", i + 1);
			printf("\n%s | %s | %d | %d |\n", mb[i].bookname, mb[i].bookauthor, mb[i].bookprice, mb[i].bookSA);
		}
		break;
	default:
		printf("다시 선택하시오.");
	}
}
void BookSearch(BOOK* mb, int cnt) {
	FILE* fp = fopen("save.txt", "r+"); //베스트셀러 수정삭제 제목저자검색
	char b[50];
	int s;
	puts("\n메뉴 선택하시오.");
	puts("1.제목검색|2.저자검색"); //제목은 키워드로
	scanf("%d", &s);
	switch (s) {
	case 1:
		getchar();
		printf("검색할 제목을 입력하시오:");
		gets(b);
		printf("\n------------------");
		printf("\n제목 | 저자 | 가격 | 수량 | 코드 |");
		for (int i = 0; i < cnt; i++) {
			if (strstr(mb[i].bookname, b) != NULL) {
				printf("\n%s | %s | %d | %d | %s |\n", mb[i].bookname, mb[i].bookauthor, mb[i].bookprice,
					mb[i].bookSA, mb[i].bookcode);
			}
			else {
				printf("\n------------------");
				printf("\n 제목과 일치하는 책이 없습니다.\n");
			}
		}
		break;
	case 2:
		getchar();
		printf("\n검색할 저자를 입력하시오:");
		gets(b);
		printf("\n------------------");
		printf("\n제목 | 저자 | 가격 | 수량 | 코드 |");
		for (int i = 0; i < cnt; i++) {
			if (strcmp(mb[i].bookauthor, b) == 0) {
				printf("\n%s | %s | %d | %d | %s |\n", mb[i].bookname, mb[i].bookauthor, mb[i].bookprice,
					mb[i].bookSA, mb[i].bookcode);
			}
			else {
				printf("\n------------------");
				printf("\n 검색한 저자의 책이 없습니다.\n");
			}
		}
		break;
	default:
		printf("다시선택하시오.\n");
	}
}
int BookDelRev(BOOK* mb, int cnt) {
	FILE* fp = fopen("save.txt", "r+"); //베스트셀러 수정삭제 제목저자검색
	char c[50];
	int d;
	int leng;
	puts("\n메뉴 선택하시오.");
	puts("1.수정|2.삭제");
	scanf("%d", &d);
	switch (d) {
	case 1: //수정
		getchar();
		printf("수정할 책 제목을 입력하시오:");
		gets(c);
		for (int i = 0; i < cnt; i++) {
			if (strcmp(mb[i].bookname, c) == 0) {
				printf("\n------------------");
				printf("\n수정하시오.");
				printf("\n제목:");
				gets(mb[i].bookname);
				printf("저자:");
				gets(mb[i].bookauthor);
				printf("가격:");
				scanf("%d", &mb[i].bookprice);
				printf("판매 수량:");
				scanf("%d", &mb[i].bookSA);
				getchar();
				while (1) {
					printf("책 코드:");
					gets(mb[i].bookcode);
					if (strlen(mb[i].bookcode) == 8) {
						leng = strspn(mb[i].bookcode, "0123456789-");
						if (leng == 8 && leng != 0) break;
					}
					printf("코드를 다시확인하시오.\n");
				}
				printf("\n------------------");
				printf("\n수정됨.");
				printf("\n제목 | 저자 | 가격 | 수량 | 코드 |");
				printf("\n%s | %s | %d | %d | %s |", mb[i].bookname, mb[i].bookauthor, mb[i].bookprice,
					mb[i].bookSA, mb[i].bookcode);
			}
			else {
				printf("\n------------------");
				printf("\n 검색한 제목과 맞는 책이 없습니다.\n");
			}
		}
		break;
	case 2: //삭제
		getchar();
		printf("삭제할 책 제목을 입력하시오:");
		gets(c);
		for (int i = 0; i < cnt - 1; i++) {
			if (strcmp(mb[i].bookname, c) == 0) {
				printf("\n------------------");
				mb[i] = mb[i + 1];
				printf("\n삭제됨.");
			}
			else {
				printf("\n------------------");
				printf("\n 검색한 제목과 맞는 책이 없습니다.\n");
			}
		}
		cnt--;
		mb = (BOOK*)realloc(mb, cnt * sizeof(BOOK));
		break;
	default:
		printf("다시선택하시오.\n");
	}
	return cnt;
}