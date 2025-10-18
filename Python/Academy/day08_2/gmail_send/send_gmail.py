# send_gmail.py
# gmail의 앱 비밀번호를 이용한
# SMTP 이메일 전송 코드

import smtplib # 기본 모듈(설치x)
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

# 기본 이메일 전송 코드
def send_email(sender_email, sender_password, receiver_email, subject: str, body):
    # 이메일 메시지 설정
    msg = MIMEMultipart()
    msg["From"] = sender_email
    msg["To"] = receiver_email
    # 이메일의 제목을 설정하는 부분
    msg["Subject"] = subject

    # 이메일 본문을 일반 텍스트로 추가
    msg.attach(MIMEText(body, "plain"))

    try: # 아래 코드에서 오류가 발생할 수 있음
        # Gmail SMTP 서버에 연결(포트 587 사용)
        server = smtplib.SMTP("smtp.gmail.com", 587)
        server.starttls() # TLS(Transport Layer Security)
        # 보안 연결 시작

        # Gmail 계정으로 로그인
        server.login(sender_email, sender_password)

        # 이메일을 문자열로 변환하고 전송
        text = msg.as_string()
        server.sendmail(sender_email, receiver_email, text)
        # 전송 안내 메시지
        print("이메일이 성공적으로 전송됨")
    except Exception as e:
        # 오류 발생 시 에러 메시지 출력
        print(f"에러 발생: \n{e}")
    finally:
        # 서버 연결 종료
        server.quit()

if __name__ == "__main__":
    import json
    import os
    data = None
    # 현재 파일 위치를 저장
    file_path = __file__
    # 현재 폴더 경로를 저장
    folder_path = os.path.dirname(file_path)
    # json 파일 경로 지정
    json_file_path = os.path.join(folder_path, 'config.json')
    # json 파일을 열어
    with open(json_file_path, 'r') as file:
        # 파일 데이터 가져오기
        data = json.load(file)
    sender_email = "soRjdla0709@gmail.com"
    app_password = "wodud0918*"
    if data: # 가져온 데이터가 있다면
        # 정보 재설정
        sender_email = data["sender_email"]
        app_password = data["password"]
    # 직접 입력하는 방식도 가능
    # 빈문자열 입력(입력없이 Enter)하면 고정된 값 입력
    receiver_email = input("받을 이메일 입력") or "jaypark0709@gmail.com"
    subject = input("이메일 제목 입력") or "test"
    body = input("내용 입력") or "test content"

    # 이메일 전송 함수 호출
    send_email(sender_email=sender_email, sender_password=app_password, receiver_email=receiver_email, subject=subject, body=body)