import time

bpm = 180  # BPM 설정
one_beat_sec = 60 / bpm  # 1비트당 초
note_mapping = {'1': '1000', '2': '2000', 'q': '1000', 'w': '0200', 'e': '0030', 'r': '0004'}
mode = 2  # 초기 원투는 2비트
base_beat = mode
prev_time = None

# 파일 이름 설정
file_name = "beat_pattern.txt"
with open(file_name, 'w') as f:
    f.write("노트 패턴\n")

print("1, 2 (원투 구간) → q, w, e, r (QWER 구간) → 0 입력 시 종료")

while True:
    key = input("입력 (1/2/q/w/e/r/0): ").lower()

    if key == '0':
        print("종료합니다.")
        break

    if key not in note_mapping:
        print("잘못된 입력입니다.")
        continue

    now = time.time()

    # 시간 간격 계산 후 비트 변환
    if prev_time is None:
        # 첫 입력이면 기본 비트로 출력
        beat = base_beat
    else:
        interval = now - prev_time
        beat_offset = round(interval / one_beat_sec)
        base_beat += beat_offset
        beat = base_beat

    # 파일에 저장
    with open(file_name, 'a') as f:
        f.write(f"{note_mapping[key]}|{beat:03}|000|000\n")

    print(f"{note_mapping[key]}|{beat:03}|000|000 저장됨")

    # QWER 구간 진입하면 mode 변경
    if key == 'q':
        mode = 4
        base_beat = mode  # Q에서 4로 시작
        prev_time = None  # 박자 새로 시작
    else:
        prev_time = now
