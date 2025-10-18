#pragma once

#include "stdafx.h"
#include "Human.h"

class Student : public Human
{
    int _SchoolYear;
    int _Class;
    int _Number;
    char _SchoolName[30];

    public :
        Student();
        Student(const char* name, int age, bool IsMan, int year, int cl, int num, const char* cn );
        void InitalizeInfo(  );
        // virtual void ShowPrintInfo();
    protected :

}; 