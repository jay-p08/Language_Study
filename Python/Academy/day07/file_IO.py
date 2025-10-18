# 파일 입출력
# 파일 입출력은 크게 3단계로 나뉜다.
# 1. 파일 열기(open)
# 2. 파일 작업(읽기/쓰기)
# 3. 파일 닫기(close)
# 파일 입출력은 반드시 열었으면 닫아줘야 한다.

# 1. 파일 열기(open)
path = input("파일명을 입력해 주세요 : ")
print(path + ".txt 파일을 실행합니다.")

# 모드 "w"는 기존에 있던 값을 모두 제거하고
# 새로 입력된 내용을 새로 작성한다.
# 그래서 되돌릴 수 없기 때문에, 사용에 주의를 요한다.
# file = open(path, "w")

file = open(path + ".txt", "r", newline='\n')

# 2. 파일 작업(읽기/쓰기)
# 쓰기
# file.write("Hello, world! Test!")
# file.write("Hello, world! Test!")
# file.write("Hello, world! Test!")

# 읽기
lines = list()
lines = file.readlines()

for line in lines :
    # 각 줄 마지막에 존재하는 개행문자 제거
    print(line.strip("\n"))

# 3. 파일 닫기(close)
file.close()