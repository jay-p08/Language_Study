
class String_myOwn():

    def __init__(self, value:int|str|float) -> None:
        self.value = value

    # 더하기 연산을 할 때 
    def __add__(self, other:int|str|float) -> any:
        self_is_num = isinstance(self.value, int) \
            or isinstance(self.value, float)
        other_is_num = isinstance(other, int) \
            or isinstance(other, float)
        # 숫자값만 들어 있다면
        if self_is_num and other_is_num :
            # 더하기 연산을 수행한다.
            return self.value + other
        else : # self 혹은 other의 값 중 하나라도 숫자형이 아니라면
            # 둘 다 문자열로 바꾸어서 연결한 후 반환한다.
            return str(self.value) + str(other) 

    # 숫자끼리 숫자로서 연산을 수행하고
    # 둘 중 하나라도 숫자형으로 바꿀 수 없는 문자열이라면
    # 연산이 아닌 연결(하나의 문자열로 바꾸는 것)을 수행한다.


if __name__ == "__main__":
    obj = String_myOwn(30)
    print(obj + 3)

            # 연산하고자 하는 값을 임시로 담을 변수 선언
#         target = 0
#         # 전달 받은 other가 String_myOwn 클래스 타입이라면
#         if isinstance(other, String_myOwn):
#             # String_myOwn의 value 속성의 값을
#             # 연산 대상 변수에 대입
#             target = other.value
#         else: # String_.. 클래스 타입이 아니라면
#             target = other
#         print(target)