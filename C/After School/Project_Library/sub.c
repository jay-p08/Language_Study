#define _CRT_SECURE_NO_WARNINGS
#include "mainh.h"

int BookInput(BOOK* mb, int cnt) {
	FILE* fp = fopen("save.txt", "a+ "); //����Ʈ���� �������� �������ڰ˻�
	int leng;
	int yn;
	while (1) {
		getchar();
		printf("����:");
		gets(mb[cnt].bookname);
		printf("����:");
		gets(mb[cnt].bookauthor);
		printf("����:");
		scanf("%d", &mb[cnt].bookprice);
		printf("�Ǹ� ����:");
		scanf("%d", &mb[cnt].bookSA);
		getchar();
		while (1) {
			printf("å �ڵ�:");
			gets(mb[cnt].bookcode);
			if (strlen(mb[cnt].bookcode) == 8) {
				leng = strspn(mb[cnt].bookcode, "0123456789-");
				if (leng == 8 && leng != 0) break;
			}
			printf("�ڵ带 �ٽ�Ȯ���Ͻÿ�.\n");
		}
		fprintf(fp, "%s %s %d %d %s\n", mb[cnt].bookname, mb[cnt].bookauthor, mb[cnt].bookprice,
			mb[cnt].bookSA, mb[cnt].bookcode);
		cnt++;
		printf("�ٽ� �Է��Ͻðڽ��ϱ�?1.Y/2.N : ");
		scanf("%d", &yn);
		if (yn == 1) {
			printf("����ۼ�!\n");
		}
		if (yn == 2) break;
		else if (yn != 1 && yn != 2) {
			printf("1,2�����ϳ�����!\n");
			break;
		}
	}
	mb = (BOOK*)realloc(mb, cnt * sizeof(BOOK));
	return cnt;
}

void BookOutput(BOOK* mb, int cnt) {
	FILE* fp = fopen("save.txt", "r"); //����Ʈ���� �������� �������ڰ˻�
	fscanf(fp, "%s %s %d %d %s", mb[cnt].bookname, mb[cnt].bookauthor, mb[cnt].bookprice,
		mb[cnt].bookSA, mb[cnt].bookcode);
	int n;
	char y[5];
	int bo;
	y[4] = '\0';
	puts("1.��ü��� | 2.���ǳ⵵��� | 3.����Ʈ����");
	scanf("%d", &n);
	switch (n) {
	case 1:
		printf("\n------------------");
		printf("\n���� | ���� | ���� | ���� | �ڵ� |");
		for (int i = 0; i < cnt; i++) {
			printf("%d�� å", i + 1);
			printf("\n%s | %s | %d | %d | %s |\n", mb[i].bookname, mb[i].bookauthor, mb[i].bookprice, mb[i].bookSA, mb[i].bookcode);
			if ((i + 1) % 10 == 0 && i != cnt - 1) {
				printf("�ƹ�Ű�� ���� ������������");
				//fgetc(stdin);
				getch();
				printf("\n------------------");
				printf("\n���� | ���� | ���� | ���� | �ڵ� |");
			}
		}
		break;
	case 2:
		getchar();
		printf("���ǳ⵵�Է�:");
		gets(y);
		int con = 0;
		char sa[9];
		printf("\n------------------");
		printf("\n���ǳ⵵\n%s", y);
		printf("\n���� | ���� | ���� | ���� |");
		for (int i = 0; i < cnt; i++) {
			strcpy(sa, mb[i].bookcode);
			if (strncmp(sa, y, 4) == 0) {
				printf("\n%s | %s | %d | %d |\n", mb[i].bookname, mb[i].bookauthor, mb[i].bookprice,
					mb[i].bookSA);
				con++;
			}
			else if (con == 0) {
				printf("�ش� �⵵�� ���� å�� �����ϴ�.");
			}
		}
		break;
	case 3:
		printf("����Ʈ�����������ϱ�:");
		scanf("%d", &bo);
		for (int i = 0; i < cnt - 1; i++) {
			int maxIndex = i;
			for (int j = i + 1; j < cnt; j++) {
				if (mb[j].bookSA > mb[maxIndex].bookSA) {  // �������� ��
					maxIndex = j;
				}
			}
			struct book temp = mb[i];
			mb[i] = mb[maxIndex];
			mb[maxIndex] = temp;
		}
		printf("\n------------------");
		printf("\n����Ʈ���� TOP%d", bo);
		printf("\n���� | ���� | ���� | ���� |");
		for (int i = 0; i < bo && i < cnt; i++) {
			printf("\n%d��", i + 1);
			printf("\n%s | %s | %d | %d |\n", mb[i].bookname, mb[i].bookauthor, mb[i].bookprice, mb[i].bookSA);
		}
		break;
	default:
		printf("�ٽ� �����Ͻÿ�.");
	}
}
void BookSearch(BOOK* mb, int cnt) {
	FILE* fp = fopen("save.txt", "r+"); //����Ʈ���� �������� �������ڰ˻�
	char b[50];
	int s;
	puts("\n�޴� �����Ͻÿ�.");
	puts("1.����˻�|2.���ڰ˻�"); //������ Ű�����
	scanf("%d", &s);
	switch (s) {
	case 1:
		getchar();
		printf("�˻��� ������ �Է��Ͻÿ�:");
		gets(b);
		printf("\n------------------");
		printf("\n���� | ���� | ���� | ���� | �ڵ� |");
		for (int i = 0; i < cnt; i++) {
			if (strstr(mb[i].bookname, b) != NULL) {
				printf("\n%s | %s | %d | %d | %s |\n", mb[i].bookname, mb[i].bookauthor, mb[i].bookprice,
					mb[i].bookSA, mb[i].bookcode);
			}
			else {
				printf("\n------------------");
				printf("\n ����� ��ġ�ϴ� å�� �����ϴ�.\n");
			}
		}
		break;
	case 2:
		getchar();
		printf("\n�˻��� ���ڸ� �Է��Ͻÿ�:");
		gets(b);
		printf("\n------------------");
		printf("\n���� | ���� | ���� | ���� | �ڵ� |");
		for (int i = 0; i < cnt; i++) {
			if (strcmp(mb[i].bookauthor, b) == 0) {
				printf("\n%s | %s | %d | %d | %s |\n", mb[i].bookname, mb[i].bookauthor, mb[i].bookprice,
					mb[i].bookSA, mb[i].bookcode);
			}
			else {
				printf("\n------------------");
				printf("\n �˻��� ������ å�� �����ϴ�.\n");
			}
		}
		break;
	default:
		printf("�ٽü����Ͻÿ�.\n");
	}
}
int BookDelRev(BOOK* mb, int cnt) {
	FILE* fp = fopen("save.txt", "r+"); //����Ʈ���� �������� �������ڰ˻�
	char c[50];
	int d;
	int leng;
	puts("\n�޴� �����Ͻÿ�.");
	puts("1.����|2.����");
	scanf("%d", &d);
	switch (d) {
	case 1: //����
		getchar();
		printf("������ å ������ �Է��Ͻÿ�:");
		gets(c);
		for (int i = 0; i < cnt; i++) {
			if (strcmp(mb[i].bookname, c) == 0) {
				printf("\n------------------");
				printf("\n�����Ͻÿ�.");
				printf("\n����:");
				gets(mb[i].bookname);
				printf("����:");
				gets(mb[i].bookauthor);
				printf("����:");
				scanf("%d", &mb[i].bookprice);
				printf("�Ǹ� ����:");
				scanf("%d", &mb[i].bookSA);
				getchar();
				while (1) {
					printf("å �ڵ�:");
					gets(mb[i].bookcode);
					if (strlen(mb[i].bookcode) == 8) {
						leng = strspn(mb[i].bookcode, "0123456789-");
						if (leng == 8 && leng != 0) break;
					}
					printf("�ڵ带 �ٽ�Ȯ���Ͻÿ�.\n");
				}
				printf("\n------------------");
				printf("\n������.");
				printf("\n���� | ���� | ���� | ���� | �ڵ� |");
				printf("\n%s | %s | %d | %d | %s |", mb[i].bookname, mb[i].bookauthor, mb[i].bookprice,
					mb[i].bookSA, mb[i].bookcode);
			}
			else {
				printf("\n------------------");
				printf("\n �˻��� ����� �´� å�� �����ϴ�.\n");
			}
		}
		break;
	case 2: //����
		getchar();
		printf("������ å ������ �Է��Ͻÿ�:");
		gets(c);
		for (int i = 0; i < cnt - 1; i++) {
			if (strcmp(mb[i].bookname, c) == 0) {
				printf("\n------------------");
				mb[i] = mb[i + 1];
				printf("\n������.");
			}
			else {
				printf("\n------------------");
				printf("\n �˻��� ����� �´� å�� �����ϴ�.\n");
			}
		}
		cnt--;
		mb = (BOOK*)realloc(mb, cnt * sizeof(BOOK));
		break;
	default:
		printf("�ٽü����Ͻÿ�.\n");
	}
	return cnt;
}