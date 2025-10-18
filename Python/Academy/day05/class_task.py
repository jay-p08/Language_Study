# 학생 클래스를 만들어서
# 객체를 생성하면서 수학점수, 영어점수, 국어점수를 입력받아
# 각각 math, eng, kor 변수에 담아서
# 외부에서 접근하여 출력해보자.
class Student() :
    def __init__(self, math, eng, kor) -> None :
        self.math = math
        self.eng = eng
        self.kor = kor
    
    def get_math(self) :
        return self.math
    def set_math(self, math) :
        self.math = math

if __name__ == "__main__" :
    kim = Student(80, 85, 70)
    print(kim.get_math())
    
    # 객체에 접근하여 메서드 사용하기
    kim.set_math(100)
    print(kim.get_math())