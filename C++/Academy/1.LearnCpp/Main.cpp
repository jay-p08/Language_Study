#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include <locale.h>

using namespace std;

enum ShowKind
{
    ALL     = 0,
    ODD,
    EVEN
};

int AddThreeValue( int val1, int val2, int val3 );
float AddThreeValue( float val1, int val2, int val3 );
float AddThreeValue( float val1, float val2, int val3 );
float AddThreeValue( float val1, float val2, float val3 );
void PrintNumberSequence( int end, int start = 1 );
void ExchangeInt( int* su1, int* su2 );
void ExchangeInt( int& su1, int& su2 );
void ShowCountDown( int count );
void ShowKind( int arr[], int menu );

int main() 
{
    srand( time( NULL ) );
    setlocale( LC_ALL, "ko_KR.UTF-8" );

    // namespace를 쓰지 않았을 때
    // std::cout << "Hello World!\n";
    // const 자료형*        <== 포인터가 가리키는 변수의 값을 바꿀 수 없다.
    // 자료형* const        <== 포인터 값을 바꿀수 없다.
    // const char* name = "홍길동";
    // int age = 19;
    // float ki = 176.8f;
    // float weight = 70.6f;
    // float bmi = weight / ((ki / 100) * (ki / 100));
    // std::cout << age << "세의 " << name << "은 " << ki << "Cm의 키에 " << weight
    //             << "Kg의 몸무게를 가지고 있고 BMI 수치는 " /*<< weight / (( ki / 100 ) * ( ki / 100 ) ) << "입니다"*/;
    // std::cout << bmi << "입니다.";
    // std::cout << std::setprecision(3) << bmi << "입니다";
    // std::cout << std::setprecision(5) << bmi << "입니다";
    // std::cout << std::setprecision(7) << bmi << "입니다";
    // std::cout << std::endl;
    // std::cout << std::setprecision(3) << 3.141592 << std::endl;
    // std::cout << std::setprecision(5) << 12345.67 << std::endl;
    // std::cout << std::setprecision(7) << 9.8965432 << std::endl;
    // std::cout.setf( std::ios::fixed );
    // std::cout.precision( 2 );
    // std::cout << bmi << "입니다" << std::endl;

    // namespace를 썼을 때
    // char name[100] = { 0, };
    // int age = 0;
    // float height, weight;
    // cout << "당신의 이름을 입력하세요 >>> ";
    // cin >> name;
    // cout << "당신의 나이를 입력하세요 >>> ";
    // cin >> age;
    // cout << "당신의 키와 몸무게를 입력하세요( 키 몸무게 ) >>> ";
    // cin >> height >> weight;
    // cout << name << "님은 " << age << "세 입니다." << endl
    //         << "키는 " << height << "Cm 이고, 몸무게는 " << weight << "Kg 입니다." << endl;
    
    // 추가된 자료형
    // byte, bool( 논리형 )
    // bool isEnd = false;
    // 제어문에서의 변경점.
    // for ( int n = 0 ; n < 5 ; n++ ) ...
    // if ( value )
    // 프로그램중 어디에서든 변수 선언이 가능하도록 바뀌었다.
    // 동적 할당/해지 문법이 바뀌었다.
    // int* arr = NULL;
    // int* pNum = NULL;
    // int count = 10;
    // if ( !arr )
    //     arr = new int[count];
    // if ( !pNum )
    //     pNum = new int;
    // *pNum = 100;
    // for ( int n = 0 ; n < count ; n++ )
    //     arr[n] = rand();
    // for ( int n = 0 ; n < count ; n++ )
    //     cout << "arr[" << n << "] = " << arr[n] << endl;
    // cout << "pNum's Value = " << pNum << ", pNum's Address in Value = " << *pNum << endl;
    // if ( pNum )
    // {
    //     delete pNum;
    //     pNum = NULL;
    // } // if()
    // if ( arr )
    // {
    //     delete[] arr;
    //     arr = NULL;
    // } // if()

    // 함수 오버로드
    // cout << "result >>> " << AddThreeValue( 12, 3, 555 ) << endl;
    // cout << "result >>> " << AddThreeValue( 42.123f, 62, 102 ) << endl;
    // cout << "result >>> " << AddThreeValue( 3.58f, 25.9f, 22 ) << endl;
    // cout << "result >>> " << AddThreeValue( 1.2f, 3.4f, 5.6f ) << endl;

    // 디폴트 매개변수
    // PrintNumberSequence( 10 );

    // 참조형 매개변수
    // int num1 = 45; int num2 = 99;
    // cout << "num1 >>> " << num1 << ", num2 >>> " << num2 << endl;
    // // ExchangeInt( &num1, &num2 );
    // ExchangeInt( num1, num2 );
    // cout << "num1 >>> " << num1 << ", num2 >>> " << num2 << endl;

    // 재귀 함수
    // ShowCountDown( 3 );

    // 문제 1
    // int row, col;
    // int** arr = NULL;
    // cout << "행의 갯수를 입력하세요 >>> ";
    // cin >> row;
    // cout << "열의 갯수를 입력하세요 >>> ";
    // cin >> col;
    // for ( int i = 0 ; i < row ; i++ )
    // {
    //     if ( !arr )
    //         arr = new int*[row];
    //     if( !arr[i] )
    //         arr[i] = new int[col];
    //     for ( int j = 0 ; j < col ; j++ )
    //         arr[i][j] = rand();
    // } // for()
    // for ( int i = 0 ; i < row ; i++ )
    // {
    //     for ( int j = 0 ; j < col ; j++ )
    //         cout << i+1 << "행 " << j+1 << "열의 값 >>> " << arr[i][j] << endl;
    //     cout << endl;
    // } // for()
    // if ( arr )
    // {
    //     for ( int i = 0 ; i < row ; i++ )
    //     {
    //         delete[] arr[i];
    //         arr[i] = NULL;
    //     } // for()
    //     delete[] arr;
    //     arr = NULL;
    // } // if()

    // 문제 2
    // int menu;
    // int arr1[10] = { 11, 22, 33, 44, 55, 66 ,77, 88, 99, 100 };
    // cout << "1. 전체보기" << endl;
    // cout << "2. 홀수 보기" << endl;
    // cout << "3. 짝수 보기" << endl;
    // cout << "배열을 어떤 방법으로 보시겠습니까 >>> ";
    // cin >> menu;
    // ShowKind( arr1, menu );

    return 0;
}

// 함수의 오버로드
// 오버 로딩은 중복 정의 라고 한다.
// 일반 함수나 맴버 함수 간에 이루어진다.
// 매개변수의 개수가 다르거나 매개변수의 자료형이 다를 경우에만 오버로드를 할 수 있다.
int AddThreeValue( int val1, int val2, int val3 )
{
    return val1 + val2 + val3;
} // AddThreeValue()
float AddThreeValue( float val1, int val2, int val3 )
{
    return val1 + val2 + val3;
} // AddThreeValue()
float AddThreeValue( float val1, float val2, int val3 )
{
    return val1 + val2 + val3;
} // AddThreeValue()
float AddThreeValue( float val1, float val2, float val3 )
{
    return val1 + val2 + val3;
} // AddThreeValue()

// 디폴트 매개변수
// 함수를 호출할 시에 매개변수를 생략할 경우 지정된 디폴트 값을 자동적으로 적용하게 하는 기능.
// 정의부만 있는 경우 정의부에서 선언하고, 선언부가 있으면 선언부에다 선언해야 한다.
void PrintNumberSequence( int end, int start )
{
    for ( int n = start; n <= end; n++ )
    {
        cout << n << endl;
    } // for()
} // PrintNumberSequence()
// void aaa( int a = 0 )
// void bbb( int a, int b = 0 )
// void ccc( int a = 0, int b = 0 )
// void ddd( int a, int b, int c = 0 )
// void eee( int a, int b = 0, int c = 0 )
// void fff( int a = 0, int b = 0, int c = 0 )
// ......

// 창조형 매개변수
// 매개변수를 창조형으로 사용할 수 있게 되었다.
// 매개변수의 자료형을 창조형으로 함으로써 주소형보다 원 기억장소의 접근성을 높인 방법이 되었다.
void ExchangeInt( int* su1, int* su2 )
{
    int t = *su1;
    *su1 = *su2;
    *su2 = t;
} // ExchangeInt()
void ExchangeInt( int& su1, int& su2 )
{
    int t = su1;
    su1 = su2;
    su2 = t;
} // ExchangeInt()

// 재귀 함수
// 함수내에서 자기 자신을 호출하는 함수를 말한다.
// 재귀함수는 반복문과 비슷한 결과를 가진다. 그래서 알고리즘에서 많이 사용된다.
void ShowCountDown( int count )
{
    if ( count < 0 )
    {
        cout << "퐈이야~~!!!" << endl;
        return;
    } // if()

    cout << "카운트 다운 " << count << "!!" << endl;
    ShowCountDown( count - 1 );
} // ShowCountDown()

void ShowKind( int arr[], enum ShowKind menu = ALL )
{
    switch ( menu )
    {
        case ALL:
            for ( int n = 0 ; n < 10 ; n++ )
                cout << "arr[" << n << "] = " << arr[n] << endl;
            break;

        case ODD:
            for ( int n = 0 ; n < 10 ; n++ )
                if ( arr[n] % 2 != 0 )
                    cout << "arr[" << n << "] = " << arr[n] << endl;
            break;

        case EVEN:
            for ( int n = 0 ; n < 10 ; n++ )
                if ( arr[n] % 2 == 0 )
                    cout << "arr[" << n << "] = " << arr[n] << endl;
            break;

        default:
            break;
    } // switch()
}