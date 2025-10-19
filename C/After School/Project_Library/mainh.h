#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct book {
	char bookname[50];
	char bookauthor[20];
	int bookprice;
	int bookSA;
	char bookcode[9];
}BOOK;

//int comp(const void* a, const void* b) {
//	return (*(int*)b - *(int*)a);
//}
int BookInput(BOOK*, int);
void BookOutput(BOOK*, int);
void BookSearch(BOOK*, int);
int BookDelRev(BOOK*, int);
