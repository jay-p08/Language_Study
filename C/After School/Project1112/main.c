#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void sub(DATA);
typedef struct data {
	char name[20];
	int age;
	double height;
}DATA;


int main() {
	DATA a[] = {{"yoon", 17, 168.3}, {"kim", 17, 184.3}, {"min", 17, 193.3}};
	char name[20];
	int age;
	double height;
	while (1) {
		int flag = 0;
		gets(name);
		if (strlen(name) < 1) break;
		for (int i = 0; i < 3; i++) {
			if (!strcmp(name, a[i].name)) {
				sub(a[i]); flag = 1;
			}
		}
		if (!flag) puts("¾øÀ½");
	}
	
	//DATA b = { "yoon", 17, 169.7 }, * p = &b;
	////printf("%s %d %lf", b.name, b.age, b.height);
	//sub(&b);
	return 0;
}
void sub(DATA a) {
	printf("%s %d %.lf \n", a.name, a.age, a.height);
}
//void sub(DATA *p) {
//	printf("%s %d %lf \n", *p->name, *p->age, *p->height);
//}