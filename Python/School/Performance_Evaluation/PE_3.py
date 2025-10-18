# 학생 목록
students = ["강일", "박삼", "정오", "이칠", "김이", "김사", "장육", "이팔"]

# 이름순 오름차순 정렬
students.sort()

# 성씨 입력
last_name = input("성씨를 입력하세요 : ")

# 해당 성씨를 가진 학생 찾기
matched = [(i + 1, name) for i, name in enumerate(students) if name.startswith(last_name)]

if not matched:
    print("해당 성씨를 가진 학생이 없습니다.")
else:
    # 학번 추출
    numbers = [num for num, _ in matched]
    
    # 모두 4번 이하인지 확인
    if all(num <= 4 for num in numbers):
        # 이름만 리스트로 출력
        print([name for _, name in matched])
    else:
        print(f"{last_name}씨는 번호가 4번 이하가 아닙니다.")
