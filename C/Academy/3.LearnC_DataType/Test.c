#include <stdio.h>

int main() {
    char name[50];
    int age = 0;
    float w = 0, h = 0;

    printf( "�̸��� �Է��ϼ��� : " );
    scanf( " %s", name );
    printf( "���̸� �Է��ϼ��� : " );
    scanf( " %d", &age );
    printf( "Ű�� �����Ը� �Է��ϼ���( Ű ������ ) : " );
    scanf( " %f %f", &h, &w );
    printf( "%s�� �ݰ����ϴ�.\n", name );
    printf( "%s���� ���̴� %d���̰�, Ű %.1fCm, ������ %.2fKg�Դϴ�.\n", name, age, h, w );

    return 0;
}