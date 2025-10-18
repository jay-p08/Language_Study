#pragma once

// 4가지 클래스의 기본 특징
// 캡슐화( Encapsulation )          : 자료와 기능을 하나로 묶어서 기능 충시르이 형태를 만든다.
// 상속성( Inheritance )            : 클래스끼리 공통된 자료를 사용하면 상속관계를 통해 공통 자료를 접근하도록 한다.
// 다형성( Polymorphism )           : 같은 클래스의 각기 다른 객체가 동일한 메세지를 통해 다른 기능을 수행하도록 한다.
// 은닉성( Information Hiding )     : 자료를 외부로 부터의 접근을 차단하여
class Human
{
    // 접근지정자라고 하고 이 키워드 이후로 쓰이는 맴버 변수, 맴버 함수의 접근 방법을 지정한다.
    // public:
    // protected:
    // private:
    // 3가지 접근지정자가 정해져 있지 않으면 private가 기본 설정이다.

    // 기본적으로 클래스내에서 맴버 변수의 접근 지정은 private이다.
    // 클래스의 성질인 은닉성에 의거, 정보를 감추는 것이 기본이다.
    bool _isMan;
    char _name[30];
    int _age;

    public :
        void InitalizeInfo( const char* name, int age, bool isMan );    // 초기화 함수
    
        virtual void ShowPrintInfo() = 0;
        void Laugh();

        // get 함수
        const char* GetMyName();
        int GetAge();
        // set 함수
        void SetMyName( const char* name );
}; // Human