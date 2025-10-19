#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct data {
	char name[20];
	int jumsu;
}DATA;

int main() {
	DATA a[] = {{"yoon", 67}, {"kim", 45}, {"bak", 90}, {"jou", 50}, {"do", 70}};
	pri(a);
	prt(a, "pass");
	//char name[20];
	//int jumsu;
	//while (1) {
	//	int count = 0;
	//	gets(name);
	//	if (strlen < 1) break;
	//	for (int i = 0; i < 5; i++) {
	//		if (!strcmp(name, a[i].name)) {
	//			pri(a[i]); count = 1;
	//		}
	//	}
	//	if (!count) puts("none");
	//}
	return 0;
}
void pri(DATA *p) {
	for (int i = 0; i < 5; i++)
		if ((p + i)->jumsu >= 70) strcpy((p + i), pri, "pass");
		else strcpy((p + i), pri, "fail");
}
void prt(DATA *p, char *opt) {
	for (int i = 0; i < 5; i++) {
		if (!stcmp((p + i), pri, opt)) printf("%s \n", (p + i)->name);
	}
}