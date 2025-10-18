#include "stdafx.h"

void Sample_Function( int num1, int num2 );
string Replace_String( string subString, const string& search, const string& replace );
void Replace_String_Place( string& subString, const string& search, const string& replace );
bool Predicate( int n );

int main()
{
    srand(time(NULL));

    // try catch, throw는 c++에서 제공하는 예외처리 매커니즘입니다.
    // try
    // {
    //     // 예외가 발생하는 영역
    //     throw 예외 객체;          // 예외를 던진다.
    // }
    // catch ( 예외 객체 )
    // {
    //     // 예외 처리 영역
    // }
    // int num1 = 0, num2 = 0;
    // cout << "두개의 정수를 입력하세요 >>> ";
    // cin >> num1 >> num2;
    // try
    // {
    //     // 일반적인 예외 처리
    //     // if( num2 != 0 )
    //     //     cout << num1 << "을( 를 ) " << num2 << "( 으 )로 나눈 몫은 " << num1 / num2 << "입니다." << endl;
    //     // else
    //     //     cout << "0으로 나눌 수 없습니다." << endl;
    //     if( num2 == 0 )
    //         throw num2;
    //     cout << num1 << "을( 를 ) " << num2 << "( 으 )로 나눈 몫은 " << num1 / num2 << "입니다." << endl;
    //     Sample_Function( num1 / num2, num2 / 2 );
    // }
    // catch ( int excption )
    // {
    //     cout << "예외 발생, 나누는 수는 " << excption << "( 이 / 가 ) 될 수 없습니다." << endl;
    // }
    // cout << "프로그램을 종료합니다." << endl;

    // string 생성
    // 1. 선언과 동시에 문자열을 넣을 수 있다. 단, 이방법으로는 'z'이렇게 문자형을 넣는 것은 안된다.
    // 2. 대신 선언 이후에는 문자형을 넣을 수 있다.
    // string myString1 = "abcd";
    // string myString2 = 'z';      <<< 이렇게는 안된다.
    // cout << "myString1 : " << myString1 << endl;
    // myString1 = 'z';
    // cout << "myString1 : " << myString1 << endl;
    // myString1 = "반가워~";
    // cout << "myString1 : " << myString1 << endl;
    
    // 문자열 추가
    // myString1 += "\n꺼져!!!";
    // cout << myString1 << endl;
    // myString1.append( "다신 보는일은 없었으면 흔다~!" );
    // cout << "================" << endl;
    // cout << myString1 << endl;
    
    // 문자열 길이( 크기 )
    // cout << "위의 문자열은 " << myString1.length() << "자 입니다." << endl;
    // cout << "위의 문자열의 크기는 [" << myString1.size() << "] 입니다." << endl;
    
    // 문자열 메모리 확인
    // cout << "myString1's Capacity <<< " << myString1.capacity() << endl;
    // cout << "myString1's Max Memory size <<< " << myString1.max_size() << endl;
    
    // 특정 위치 문자 받기
    // string dlg1 = "hello world!!";
    // string dlg2 = "hello world!?";
    // cout << "dlg1's 3nd character = " << dlg1.at(2) << endl;
    // cout << "dlg2's 8nd character = " << dlg2[7] << endl;
    
    // 특정 문자열 탐색
    // cout << "world text inside dlg1 = " << dlg1.find("world") << endl;
    // cout << "!? text inside dlg2 = " << dlg2.find("!?") << endl;
    
    // 문자열 비교
    // cout << "dlg1 and dlg2 same string : " << ( ( dlg1.compare( dlg2 ) == 0 ) ? "같다" : "다르다" ) << endl;
    
    // 형변환
    // dlg1 = "123";
    // cout << "dlg1 + 22 to Integer = " << stoi( dlg1 ) + 22 << endl;
    // cout << "dlg1 + 22 to String = " << dlg1 + to_string( 22 ) << endl;

    // 문자열 대체
    // string replace = "Hello C++ !! I love C++";
    // cout << "Origin string : " << replace << endl;
    // cout << "ReplaceString() 반환값 : " << Replace_String( replace, "lo", "?!?!" ) << endl;
    // cout << "Origin string : " << replace << endl;
    // cout << "==[원본 Data값이 변하지 않았다]======" << endl << endl;
    // cout << "Replace_String_Place() 실행" << endl;
    // Replace_String_Place( replace, "lo", "아옳" );
    // cout << "Origin string : " << replace << endl;
    // cout << "==[원본 Data값이 변했다]============" << endl << endl;

    // list
    // list는 Linked list로서 인잘르 템플릿으로 구현한 특징이 있다.
    // 길이가 가변적이며 데이타의 삽입 삭제가 용이한 구조이다.
    // 임의 접근은 어려우며 순차적 접근을 많이 하는 경우 사용된다.
    // type 종류
    // list<자료형> 변수명
    // list<자료형>::iterator 변수명
    // list<자료형>::reverse_iterator 변수명
    // list<자료형>::size_type 변수명
    // 사용 가능 연산자
    // ==, !=, <, >
    // 필수 함수
    // lt.push_back( value ) : value값을 맨 뒤에 추가.
    // lt.insert( index, value ) : index 위치에 value값을 추가.
    // lt.remove( value ) : list에서 value를 모두 지움.
    // lt.erase( iter ) : iter이 가리키는 원소를 제거.
    // lt.clear() : 모든 원소를 제거.
    // lt.empty() : list가 비어있는지 조사( true, false )
    // lt.begin() : lt의 첫번째 원소를 가리키는 iter를 반환.
    // lt.size() : list의 원소 개수를 반환.
    // lt.max_size() : llist가 담을 수 있는 최대 원소 개수.
    // lt.merge( lt2 ) : lt와 lt2를 합병 정렬.
    // lt.reverse() : lt의 순차열을 뒤집음.
    // lt.sort() : list의 모든 원소를 오름차순으로 뒤집음.
    // lt.swap( lt2 ) : lt와 lt2를 swap한다.
    // list<int> lt;
    // lt.push_back( 10 );
    // lt.push_back( 20 );
    // lt.push_back( 30 );
    // lt.push_back( 40 );
    // lt.push_back( 50 );
    // list<int>::iterator iter;
    // for( iter = lt.begin() ; iter != lt.end(); ++iter )
    // {
    //     cout << *iter << " ";
    // }
    // cout << endl;
    // iter = lt.begin();
    // iter++;
    // iter++;
    // list<int>::iterator iter2 = lt.erase( iter );
    // for( iter = lt.begin() ; iter != lt.end(); ++iter )
    // {
    //     cout << *iter << " ";
    // }
    // cout << endl;
    // cout << "iter2 : " << *iter2 << endl;
    // lt.push_back( 10 );
    // lt.push_back( 10 );
    // for( iter = lt.begin() ; iter != lt.end(); ++iter )
    // {
    //     cout << *iter << " ";
    // }
    // cout << endl;
    // // 리스트에서 원소 10 제거
    // lt.remove( 10 );
    // for( iter = lt.begin() ; iter != lt.end(); ++iter )
    // {
    //     cout << *iter << " ";
    // }
    // cout << endl;
    // // Predicate 함수에 해당하는 원소 제거( 30보다 크다 )
    // lt.remove_if( Predicate );
    // for( iter = lt.begin() ; iter != lt.end(); ++iter )
    // {
    //     cout << *iter << " ";
    // }
    // cout << endl;

    // vector
    // vector는 번호와 번호에 대응하는 데이터로 이루어진 ArrayList 구조를 가진다.
    // 배열과 유사한 구조를 가지지만 배열과 다르게 크기가 동적으로 변한다는 차이점이 있다.
    // 임의 접근이 가능하며 자료를 순차적으로 저장한다.
    // 중간에 자료의 삽입, 삭제가 용이하지 않으며 검색을 할 경우 느리다.
    // type 종류
    // vector<자료형> 변수명
    // vector<자료형>::iterator 변수명
    // vector<자료형>::reverse_iterator 변수명
    // vector<자료형>::size_type 변수명
    // 사용 가능 연산자
    // ==, !=, <, >, []
    // 필수 함수
    // vt.push_back( value ) : value값을 맨 뒤에 추가.
    // vt.insert( index, value ) : index 위치에 value값을 추가.
    // vt.erase( iter ) : iter이 가리키는 원소를 제거.
    // vt.clear() : 모든 원소를 제거.
    // vt.empty() : vector가 비어있는지 조사( true, false )
    // vt.begin() : vt의 첫번째 원소를 가리키는 iter를 반환.
    // vt.size() : vector의 원소 개수를 반환.
    // vt.max_size() : vector가 담을 수 있는 최대 원소 개수.
    // vt.capacity() : vector가 할당한 메모리 크기.
    // vt.resize( size ) : vector의 크기를 size로 변경.
    // vt.reserve( size ) : vector의 크기를 size로 변경하지 않고 메모리만 확보.
    // vt.swap( vt2 ) : vt와 vt2를 swap한다.
    // vt.at( index ) : index 위치의 원소를 반환.
    // vector<int> v;
    // v.reserve( 8 ); // 벡터 메모리 공간 8 예약 할당
    // v.push_back( 10 );
    // v.push_back( 20 );
    // v.push_back( 30 );
    // v.push_back( 40 );
    // v.push_back( 50 );
    // for( vector<int>::size_type i = 0 ; i < v.size(); ++i )
    //     cout << v[i] << endl;
    // cout << endl;
    // cout << "v.size() : " << v.size() << endl; // 벡터의 크기
    // cout << "v.capacity() : " << v.capacity() << endl; // 벡터의 용량
    // cout << "v.max_size() : " << v.max_size() << endl; // 벡터의 최대 크기
    // cout << endl << "--resize( 10 ) 실행--" << endl;
    // v.resize( 10 ); // 벡터의 크기를 10으로 변경
    // for( vector<int>::size_type i = 0 ; i < v.size(); ++i )
    //     cout << v[i] << endl;
    // cout << endl;
    // cout << "v.size() : " << v.size() << endl; // 벡터의 크기
    // cout << "v.capacity() : " << v.capacity() << endl; // 벡터의 용량
    // cout << "v.max_size() : " << v.max_size() << endl; // 벡터의 최대 크기
    // cout << endl << "--resize( 3 ) 실행--" << endl;
    // v.resize( 3 ); // 벡터의 크기를 3으로 변경
    // for( vector<int>::size_type i = 0 ; i < v.size(); ++i )
    //     cout << v[i] << endl;
    // cout << endl;
    // cout << "v.size() : " << v.size() << endl; // 벡터의 크기
    // cout << "v.capacity() : " << v.capacity() << endl; // 벡터의 용량
    // cout << "v.max_size() : " << v.max_size() << endl; // 벡터의 최대 크기
    // cout << endl << "--vector clear()--" << endl;
    // v.clear(); // 벡터의 모든 원소 제거
    // if( v.empty() )
    //     cout << "벡터가 비어있습니다." << endl;
    // cout << "v.size() : " << v.size() << endl; // 벡터의 크기
    // cout << "v.capacity() : " << v.capacity() << endl; // 벡터의 용량
    // cout << "v.max_size() : " << v.max_size() << endl; // 벡터의 최대 크기
    // cout << endl;

    // map
    // map의 자료 구조는 레드 블랙 트리를 사용합니다.
    // 트리의 특정 노드값( key )를 기준으로 작은 값은 왼쪽 서브트리, 큰 값은 오른쪽 서브트리에 저장됩니다.
    // 서브트리에 저장되어 있는 특정값( key )를 찾을때 선형 자료구조보다 빠르게 찾을 수 있습니다.
    // 트리 자료 구조는 깊이가 작을 수록 성능에 유리하므로 균형있게 저장되는 것이 중요합니다.
    // 저장된 자료를 정렬하기 쉽고, 특정 자료에 대한 검색이 매우 빠른 장점이 있습니다.
    // 또한 많은 자료일 수록 강점이 두드러집니다.
    // 삽입, 삭제는 빈번하게 하지 않습니다.
    // type 종류
    // map<key 자료형, value 자료형> 변수명
    // map<key 자료형, value 자료형>::iterator 변수명
    // map<key 자료형, value 자료형>::reverse_iterator 변수명
    // map<key 자료형, value 자료형>::size_type 변수명
    // 사용 가능 연산자
    // []
    // 필수 함수
    // insert( pair<key 자료형, value 자료형> ) : key와 value를 쌍으로 삽입.
    // find( key ) : key에 해당하는 value를 찾음.
    // map<int, int> m;
    // m.insert( pair<int, int>( 5, 100 ) ); // 임의 pair insert()
    // m.insert( pair<int, int>( 3, 100 ) );
    // pair<int, int> p( 9, 50 );
    // m.insert( p ); // pair 객체 생성 insert()
    // m[11] = 200; // key/value 삽입
    // m[12] = 200;
    // m[13] = 40;
    // map<int, int>::iterator iter;
    // for( iter = m.begin() ; iter != m.end(); ++iter )
    //     cout << "key : " << iter->first << ", value : " << iter->second << endl;
    // cout << endl;
    // m[13] = 140;
    // for( iter = m.begin() ; iter != m.end(); ++iter )
    //     cout << "key : " << iter->first << ", value : " << iter->second << endl;
    // cout << endl;
    // pair<map<int, int>::iterator, bool> pr;
    // // insert 결과 성공
    // pr = m.insert( pair<int, int>( 10, 30 ) );
    // if( true == pr.second )
    //     cout << "insert 성공, key : " << pr.first->first << ", value : " << pr.first->second << endl;
    // else
    //     cout << "insert 실패, key : " << pr.first->first << ", value : " << pr.first->second << endl;
    // for( iter = m.begin() ; iter != m.end(); ++iter )
    //     cout << "key : " << iter->first << ", value : " << iter->second << endl;
    // cout << endl;
    // pr = m.insert( pair<int, int>( 10, 40 ) );
    // if( true == pr.second )
    //     cout << "insert 성공, key : " << pr.first->first << ", value : " << pr.first->second << endl;
    // else
    //     cout << "insert 실패, key : " << pr.first->first << ", value : " << pr.first->second << endl;

    

    return 0;
}
void Check_Number( int number )
{
    if( number == 0 )
        throw number;
}
void Sample_Function( int num1, int num2 )
{
    if( num1 < 1 )
        return;
    Check_Number( num2 );
    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
    Sample_Function( num1 / num2, num2 / 2 );
}

string Replace_String( string subString, const string& search, const string& replace )
{
    size_t pos = 0;
    while( pos = subString.find( search, pos ) != string::npos )
    {
        subString.replace( pos, search.length(), replace );
        pos += replace.length();
    }
    return subString;
}
void Replace_String_Place( string& subString, const string& search, const string& replace )
{
    size_t pos = 0;
    while( ( pos = subString.find( search, pos ) ) != string::npos )
    {
        subString.replace( pos, search.length(), replace );
        pos += replace.length();
    }
}

bool Predicate( int n )
{
    return n >= 30;
}
