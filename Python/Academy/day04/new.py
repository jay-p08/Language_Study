# 상단은 임포트 하는 공간.

# 중단은 코드를 작성하는 공간.
# 함수(function), 메서드(method)
# 기능을 미리 정의해두는 하나의 기능 부품이다.
# 1. define -> def를 작성한 뒤, 함수의 이름을 작성
# 2. 함수명 뒤에는 소괄호를 연다.
# 3. 소괄호 안에는 기능을 수행하는 데 필요한 값을 담을 변수명을 적는다. ( 파라미터 )
# 4. 함수 작성 공간을 구분하기 위해 콜론(:)을 적고
# 5. 줄바꿈 한 뒤, 들여쓰기를 한번 한다.
# def function_name(var1, var2) :
#   로직이 실행될 공간

def print_hello() :
    print("Hello, world")

# 전역변수
# 함수와 동일한 위계에서 선언된 변수는 함수 내부에서
# 접근이 가능하다.
val = None

# 입력값을 받아서 값을 세팅해보자. ( 각 파이썬 실행은 독립적이다. )
def set_variable(input_val) :
    global val # 전역변수 가져오기
    val = input_val
    print(val)

# 하단은 코드를 테스트 하는 공간.
# 이 파일을 직접 실행하는 경우
if __name__ == "__main__" :
    # 아래 코드가 실행된다.
    set_variable("홍길동")
    print(val)