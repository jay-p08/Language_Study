class Num:
    def __init__(self, value) -> None:
        self.value = value
    
    # __str__(self)
    # 출력했을 때 나오는 값을 설정하는 매직 메서드
    def __str__(self) -> str:
        # 해당 클래스 타입을 가지고 있는지 확인하는 함수
        if isinstance(self.value, Num):
            return str(self.value.value)
        else:
            return str(self.value)
    
    def __add__(self, other):
        print(self.value)
        print(other.value)
        return self.value + (other.value if isinstance(other, Num) else other)
    
    def __len__(self):
        return len(str(self.value))
    
if __name__ == "__main__":
    n = Num(30)
    n2 = Num(15)
    # print(str(n)) # 30
    # print(n)      # 30
    
    print(n + n2)
    print(len(n))
    print(len(312))