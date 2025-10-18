#include "stdafx.h"

#include "My_Class.h"

int My_Class::Number = 0;   // 실질적 메모리 등록

My_Class::My_Class()
{
    Count = 0;
} // My_Class()

int My_Class::Add_Three_Number(int A, int B, int C)
{
    return A + B + C;
} // Add_Three_Number()
int My_Class::Multy_Three_Number(int A, int B, int C)
{
    return A * B * C;
} // Multy_Three_Number()