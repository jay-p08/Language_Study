#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int main() {
	//char str[15] = "����";
	//printf("%s", str);

	//char s[20];
	//printf("�Է��Ͻÿ�:");
	//scanf("%s", s);
	//printf("%s", s);

	//char s[20], ch;
	//ch = getchar(); getchar();
	//putchar(ch);
	//printf("\n");
	//ch = getchar();
	//putchar(ch);

	//char ch;
	//int mo = 0;
	//while (1) {
	//	if ((ch = getchar()) != EOF) {
	//		if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
	//		mo++;
	//		//putchar(ch);
	//	}
	//	else {
	//		break;
	//	}
	//}
	//printf("%d", mo);

	//char ch;
	//ch = getchar();
	//putchar(ch); printf("\n");
	//ch = _getche();
	//putchar(ch);

	//char a[20];
	//char b[20];
	//int i = 0;
	//gets(a);
	//while (a[i] != '\0') {
	//	b[i] = a[i];
	//	i++;
	//}
	//b[i] = '\0';
	//	puts(b);

	//char ch[6];
	//int i = 0;
	//for (int i = 0; i < 5; i++)
	//scanf("%c", &ch[i]);
	//ch[i] = '\0';
	//puts(ch);

	//char ch;
	//scanf("%c", &ch);
	//if (ch >= 'a' && ch <= 'z')
	//	putchar(toupper(ch));
	//else if(isupper(ch))
	//	putchar(tolower(ch));

	char id[6];
	char mem[6] = "admin";
	int i = 0;
	int cou = 0;
	while (1) {
		scanf("%s", id);
		if (!strcmp(id, mem)) { //strcmp == ���ڿ� ��
			printf("�α��� ����!!");
			return 0;
		}
		else if (strlen(id) >= 6) { //strlen == ���ڿ� ũ�� Ȯ��
			printf("6���� �ѱ�");
		}
		else{
			printf("���� \n");
			cou += 1;
			printf("%dȸ ���� \n", cou);
			if (cou == 3) {
				return 0;
			}
		}
	}

	return 0;
}