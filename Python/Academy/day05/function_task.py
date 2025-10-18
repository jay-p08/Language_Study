# 함수
# 외부에서 매개변수에 담을 값을 전달받아
# 매개변수로 처리할 로직을 작성해놓은
# 추상적인 기능 블록을 의미한다.
# def add_nums(num1, num2) :
#     return num1 + num2

# print(add_nums(num1 = 3, num2 = 5))

# 두개의 숫자와 연산자를 문자열로 입력받아
# 문자열 연산자에 따라 결과값을 다르게 retrun하는 함수 만들기

def caculator(num1, num2, oper) : 
    return num1 + num2 if oper == "+" else num1 - num2 if oper == "-" else num1 * num2 if oper == "*" else num1 / num2

print("3 + 5 = ", caculator(3, 5, "+"))
print("5 - 3 = ", caculator(5, 3, "-"))
print("3 * 5 = ", caculator(3, 5, "*"))
print("10 / 2 = ", caculator(10, 2, "/"))