# 리스트 컴프리헨션(Comprehension)
# 대괄호에 for문 내용을 한 줄로 압축해서
# 그 결과 나오는 값들을 요소로 하는
# 새로운 리스트를 만드는 문법
new_list = [e for e in range(10)]
# 0부터 9까지의 숫자 값들을 요소로 하는 새로운 리스트 생성

print(new_list)

# 반복할 수 있는 객체(iterable object)의 요소에
# 반복적인 작업을 간단하게 할 때 사용하기도 한다.
[print(e, end=" ") for e in new_list]
print("\n")

# 리스트 컴프리헨션 with if
# 리스트 컴프 뒤에 if문을 붙여서
# 조건을 만족하는 요소에 대해서만
# 반복작업을 수행하게 할 수 있다.
even_list = [e for e in range(100+1) if e % 2 == 0]
print(even_list)

