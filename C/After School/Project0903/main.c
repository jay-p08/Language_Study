#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a[4][3] = { {3,7,2} , {5,3,6} , {2,1,9} , {4,2,8} };
	int b[4][3] = { {6,1,7} , {2,9,8} , {7,6,2} , {5,4,1} };
	int c[4][3];
	int row_size = sizeof(a) / sizeof(a[0]); // ��������
	int col_size = sizeof(a[0]) / sizeof(int); // �೪����
	for (int i = 0; i < row_size; i++) //�� �ݺ���
		for (int j = 0; j < col_size; j++) //�� �ݺ���
			c[i][j] = a[i][j] + b[i][j];
			for (int i = 0; i < row_size; i++) {
				for (int j = 0; j < col_size; j++)
				printf("%4d", c[i][j]);
				printf("\n");
	}

	return 0;
}