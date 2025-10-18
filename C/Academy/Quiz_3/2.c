#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#include <windows.h>

void Rotto();

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "ko_KR.UTF-8");
    int menu = 0;

    do
    {
        printf("1. 로또 번호 생성\n");
        printf("2. 나가기\n");
        printf("번호를 입력하세요 >>> ");
        scanf("%d", menu);
        if( menu == 2 ) break;

        printf("생성된 번호는 ");
        Rotto();

    } while ( 1 );

    return 0;
} // main()

void Rotto()
{
    int i, j, num;
    int arr[7] = {
        0,
    };

    for (i = 0; i < 7; i++)
    {
        num = rand() % 45 + 1;
        for (j = 0; j < i; j++)
            if (arr[j] == num)
                i--;
        arr[i] = num;
    }
    for (i = 0; i < 6; i++)
    {
        for (j = i + 1; j < 7; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (i = 0; i < 6; i++)
        printf("%d, ", arr[i]);
    printf( "보너스 점수는 %d 입니다.\n", arr[6] );
}