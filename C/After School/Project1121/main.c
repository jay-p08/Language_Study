#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void memoris(SUB);
typedef struct sub {
	char code[3];
	char name[20];
	int year;
	char area[20];
	char mg[2];
}SUB;

int main() {
	SUB a;
	char code[3] = {{'00'}, {'01'}, {'02'}};
	char mg[2] = { {'1'}, {'2'} };
	printf("������ �Է�:");
	gets(&a.name, &a.year, &a.area, &a.code , &a.mg);
	puts("���Է�");
	gets(a.name);
	memoris(a);
	return 0;
}
void memoris(SUB a) {
	a.year = 2024 - a.year;
	if (strchr(a.name, '\0')) {
		printf("�̸�: %s ����: %s ��������: %s ����: %s ����: %s", &a.name, &a.year, &a.area, &a.code, &a.mg);
	}
}