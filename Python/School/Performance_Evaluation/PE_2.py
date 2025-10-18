# 입력 받기
nums = list(map(int, input("정수를 입력하시오. : ").split()))

print(f"입력한 정수 리스트 {nums}")

# 각 일의 자리 숫자 개수 세기
count = {}  # {일의 자리: 개수}

for n in nums:
    last_digit = n % 10
    count[last_digit] = count.get(last_digit, 0) + 1

# 작은 수부터 출력 (개수가 0인 건 제외)
for digit in sorted(count):
    print(f"{digit} : {count[digit]}개")