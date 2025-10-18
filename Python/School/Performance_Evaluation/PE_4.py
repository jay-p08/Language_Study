temps = []

for month in range(1, 5):
    t = float(input(f"{month}월의 평균 온도 : "))
    # 중복이면 추가 안 함
    if t in temps:
        continue
    # 알맞은 위치에 삽입 (내림차순)
    inserted = False
    for i in range(len(temps)):
        if t > temps[i]:  # 큰 값이 앞쪽
            temps.insert(i, t)
            inserted = True
            break
    if not inserted:  # 끝까지 작아서 뒤에 삽입
        temps.append(t)

print("내림차순으로 정렬된 평균 온도 :", temps)
