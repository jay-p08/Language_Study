#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    srand((unsigned)time(0));
    int A;
    cout << "마지막 수 : ";
    cin >> A;
    int* v = new int[A];
    for( size_t i = 0 ; i < A ; i++ )
        v[i] = 0;

    cout << "원본데이터 : ";
    for (size_t i = 0; i < 30; i++)
    {
        int T = ( rand() % A ) + 1 ;
        cout << T << " ";
        v[ T - 1 ]++;
    } // for
    cout << endl;
    for (size_t i = 0; i < A; i++)
    {
        cout << i + 1 << " : " << v[i] << "개" << endl;
    }

    return 0;
}