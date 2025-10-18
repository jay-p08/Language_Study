#pragma once

#define SAFE_DELETE(p)          if (p) { delete p; p = 0; }
#define SAFE_DELETE_ARRAY(p)    if (p) { delete[] p; p = 0; }

enum Grade_Office
{
    STAFE,
    ASSISTANT,
    MANAGER,
    DEPUTY,
    DIRECTOR,
    PRESIDENT
};

// 구조체
// 구조체는 사용자가 만들어 사용하는 자료형이다.
// 배열과는 다르게 복합 자료를 사용하는 형태로 일정한 자료의 집합으로 사용된다.
// 동일한 구조체끼리는 치환( 복사 / 대입 )이 된다.
// 구조체 생성 키워드 : struct
// 사용 형식
// struct 구조체자료형명
// {
//    자료형 필드명1;
//    ......
//    C++에서는 메소드도 추가가 된다.
// }
// 만든 구조체를 사용시에는 : struct 구조체자료형명 변수명;
// C++에서는 : 구조체자료형명 변수명;

// 다중 구조체
// 다중 구조체란 구조체 안에 다른 구조체를 사용하는 것을 말한다.
// 사용형식
// struct 구조체자로형명1
// {
//      자료형 필드명들;
// }
// struct 구조체자료형명2
// {
//      자료형 필드명들;
//      struct 구조체자료형명1 필드명;
// }

// 자기 참조 구조체
// 자기 참조 구조체는 구조체 안에 자기 자신의 구조체 주소형이 있는 경우를 말한다.
// 사용 형식
// struct 구조체 자료형명
// {
//     자료형 필드들;
//     struct 구조체자료형명 *필드;
//     ......
// }

// typedef struct St_Name_Card
// {
//     char Name[20];
//     char Phone_Number[15];
//     char Email_Address[30];
//     Grade_Office My_Grade;

//     St_Name_Card()
//     {
//         strcpy_s( Name, sizeof( Name ), "아무개");
//         strcpy_s( Phone_Number, sizeof( Phone_Number ), "000-0000-0000");
//         strcpy_s( Email_Address, sizeof( Email_Address ), "000000@0000.000");
//         My_Grade = STAFE;
//     }

//     const char *Gt_String_To_Grade(Grade_Office Grade)
//     {
//         switch (Grade)
//         {
//         case STAFE:
//             return "사원";
//         case ASSISTANT:
//             return "대리";
//         case MANAGER:
//             return "과장";
//         case DEPUTY:
//             return "부장";
//         case DIRECTOR:
//             return "이사";
//         case PRESIDENT:
//             return "사장";
//         default:
//             return "오류";
//         }
//     }

//     void Print_Name_Card(LP_NAME_CARD Card)
//     {
//         printf("==================================\n");
//         printf("이름 >>> %s\t\t\t\n", Name);
//         printf("전화번호 >>> %s\t\n", Phone_Number);
//         printf("이메일 >>> %s\t\n", Email_Address);
//         printf( "직급 >>> %d\t\t\t\n", Gt_String_To_Grade( My_Grade ) );
//         printf( "==================================\n" );
//     }
// } NAME_CARD, *LP_NAME_CARD;

typedef struct St_Scores
{
    int Kor;
    int Eng;
    int Math;
    float Average;

    void Init( int Kor, int Eng, int Math )
    {
        this->Kor = Kor;
        this->Eng = Eng;
        this->Math = Math;
        this->Average = (Kor + Eng + Math) / 3.0f;
    }

} SCORES, *LP_SCORES;

typedef struct St_Student_Grade_Info
{
    char Name[20];
    SCORES Mid_Term;
    SCORES Final_Term;
    float Total_Average;
    int Total_Rank;
    St_Student_Grade_Info* PrevRank;
    St_Student_Grade_Info* NextRank;

    void Print()
    {
        cout << "── [" << Name << "님 정보]──────────" << endl;
        cout << " 이름 >>> " << Name << endl;
        cout << "=====중간고사 점수 ============" << endl;
        cout << " 국어 >>> " << Mid_Term.Kor << endl;
        cout << " 영어 >>> " << Mid_Term.Eng << endl;
        cout << " 수학 >>> " << Mid_Term.Math << endl;
        cout << " 평균 >>> " << Mid_Term.Average << endl;
        cout << "=====기말고사 점수 ============" << endl;
        cout << " 국어 >>> " << Final_Term.Kor << endl;
        cout << " 영어 >>> " << Final_Term.Eng << endl;
        cout << " 수학 >>> " << Final_Term.Math << endl;
        cout << " 평균 >>> " << Final_Term.Average << endl;
        cout << "==============================" << endl;
        cout << " 총 평균 >>> " << Total_Average << endl;
        cout << "────────────────────────────────────────" << endl << endl;
    }
} STUDENT_GRADE_INFO, *LP_STUDENT_GRADE_INFO;