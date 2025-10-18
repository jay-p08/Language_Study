#include "stdafx.h"

#include "Human.h"

void Human::InitalizeInfo( const char* name, int age, bool isMan )
{
    // strcpy_s( _name, sizeof( _name ), name );
    _age = age;
    _isMan = isMan;
} // InitalizeInfo()

// void Human::ShowPrintInfo()
// {
//     cout << "이름 >>> " << _name << endl;
//     cout << "나이 >>> " << _age << "세" << endl;
//     cout << "성별 >>> " << ( _isMan ? "남자" : "여자" ) << endl; 
// } // ShowPrintInfo()
void Human::Laugh()
{
    cout << _name << "님이 ";
    if ( _isMan )
        cout << "하하하 하고 웃었습니다" << endl;
    else
        cout << "호호호 하고 웃었습니다" << endl;
} // Laugh()

const char *Human::GetMyName()
{
    return _name;
} // GetMyName()
int Human::GetAge()
{
    return _age;
} // GetAge()

void Human::SetMyName(const char *name)
{
    // strcpy_s( _name, sizeof( _name ), name );
} // SetMyName()
