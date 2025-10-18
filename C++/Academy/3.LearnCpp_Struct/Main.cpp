#include "stdafx.h"

int main()
{
    srand(time(NULL));
    setlocale( LC_ALL, "ko_KR.UTF-8" );

    // NAME_CARD My_Name_Card;
    // // memset( &My_Name_Card, 0, sizeof( struct St_Name_Card ) );
    // // ZeroMemory( &My_Name_Card, sizeof( struct St_Name_Card ) );
    // strcpy_s( My_Name_Card.Name, sizeof( My_Name_Card.Name ), "홍길동" );
    // strcpy_s( My_Name_Card.Phone_Number, sizeof( My_Name_Card.Phone_Number ), "010-1234-5678" );
    // strcpy_s( My_Name_Card.Email_Address, sizeof( My_Name_Card.Email_Address ), "gd_Hong@amn.com" );
    // My_Name_Card.My_Grade = PRESIDENT;
    // My_Name_Card.Print_Name_Card( &My_Name_Card );

    STUDENT_GRADE_INFO Boy;
    Boy.Print();

    // STUDENT_GRADE_INFO StudentList[10];
    // for (int i = 0; i < 10; ++i)
    // {
    //     char name[20];
    //     cout << i + 1 << "번째 학생이름 >>> " << endl;
    //     cin >> name;
    //     StudentList[i] = Setting_Student_Info( name );
    // } cout << "10명의 학생이름을 모두 입력받았습니다." << endl;

    return 0;
}

STUDENT_GRADE_INFO Setting_Student_Info( const char* name )
{
    STUDENT_GRADE_INFO Info;
    strcpy( Info.Name, name );
    // strcpy_s( Info.Name, sizeof( Info.Name ), name );
    Info.Mid_Term.Init( rand() % 59 + 42, rand() % 59 + 42, rand() % 59 + 42 );
    Info.Final_Term.Init( rand() % 59 + 42, rand() % 59 + 42, rand() % 59 + 42 );
    Info.Total_Average = (Info.Mid_Term.Average + Info.Final_Term.Average) / 2.0f;

    return Info;
}