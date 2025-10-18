class Student :
    # 클래스 변수
    # 클래스명.으로 접근하는 객체ㅗ하없이 접근할 수 있는
    # 공용 변수를 의미한다.
    # name = "홍길동"
    school = "한국대학교"

    def __init__(self, name) -> None :
        # self.으로 접근하는 변수는
        # 멤버 변수, 인스턴스 변수 등으로 불린다.
        self.name = name

if __name__ == "__main__" :
    hong = Student("홍길동")
    go = Student("고길동")
    # print(Student.school)
    print(hong.school) # 한국대학교
    Student.school = "남한대학교"
    print("go", go.school) # "남한대학교"
    print("hong", hong.school) # "남한대학교"
    print("Student", Student.school) # "남한대학교"