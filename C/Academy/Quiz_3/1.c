#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#include <windows.h>

int StringLength( char* str );

int main() {
    srand( time( 0 ) );
    setlocale(LC_ALL, "ko_KR.UTF-8");
    char input[100];

    printf( "문자열을 입력하세요 >>> " );
    gets( input );

    printf( "입력하신 문자열은 %d개의 문자로 이루어져 있습니다\n", StringLength( input ) );

    return 0;
} // main()

int StringLength( char* str )
{
    int length = 0;
    while ( str[length] != '\0' ) {
        length++;
    }
    return length;
}