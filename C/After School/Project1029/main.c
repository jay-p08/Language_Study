#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//구조체(자바에서 클래스)
struct My {
	//char name[20];
	//int kor;
	//int eng;
	//double avg;

	char name[20];
	int age;
	double height;


};

int main() {

	struct My b;
	gets(b.name);
	scanf("%d %lf", &b.age, &b.height);
	printf("이름: %s \n 나이: %d \n 키: %lf",b.name, b.age, b.height);
	printf("My 구조체의 크기 = %d \n", sizeof(struct My));

	return 0;
}
/*strcat 문자열 연결 ,strchr 문자열에서 문자를 찾는 함수 위치*/
//char ch[10] = "hello", *p; int i = 0;
//p = strchr(ch, 'e');
//puts(p);

//char a[20], * p;
//gets(a);
//p = strchr(a, ' ');
//*p = '\0';
//puts(a);

//char a[20], *p;
//gets(a);
//p = strchr(a, '-');
//if (*(p+1) == '1') {
//	puts(a);
//	printf("합격");
//}
//else{
//	puts(a);
//	printf("불합격");
//}

//char a[5][30], * p; int count = 0;
//for (int i = 0; i < 5; i++) {
//	gets(a);
//	p = strstr(a, "kim");
//	if (*(p) == *(p)) {
//		count++;
//	}
//}
//printf("%d \n", count);
//puts(a);

//char a[5][50], *p; int cou = 0,max = 0, max_index;
//for (int i = 0; i < 5; i++) gets(a[i]);
//for (int i = 0; i < 5; i++) {
//	if (strlen(a[i] > max)) {
//		max = strlen(a[i]);
//		max_index = i;
//	}
//	if (strstr(a[i], "kim")) cou++;
//}
//printf("max %s \n", a[max_index]);
//printf("kim %d \n", cou);

//char ch[5][50], *p; int leng = 5;

//for (int i = 0; i < 5; i++)
//	gets(ch);
//	p = ch;
//	if (strlen(p) < leng) {
//		printf("오류!");
//	}
//printf(ch);

//char ch[5][50], id[20], * p; int i = 0;
//do {
//	do {
//		printf("아이디 입력:");
//		gets(ch);
//	} while (strlen(id) < 5);
//	strcpy(ch[i++], p);
//} while (i < 5);