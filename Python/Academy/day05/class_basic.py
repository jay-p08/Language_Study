# 클래스와 메서드

class Person() :

    def __init__(self, name, age, gender) -> None:
        # 이름, 나이, 성별
        self.name = name
        self.age = age
        self.gender = gender
        self.print_infos()
        # 되돌려줄 값(주소값)이 정해져 있기 때문에
        # 초기화메서드(__init__)는 retrun을 반스디 None으로 해주어야 한다.

    def print_infos(self) :
        print(self.name, self.age, self.gender)

if __name__ == "__main__" :
    # 객체화
    # 클래스라는 개념을 실체화한(구체화한)
    # 대상을 만드는 것이다.
    hong = Person("honggildong", 17, "남")
    kim = Person("kimC", 16, "여")