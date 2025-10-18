import socket
import cv2
import numpy as np
import json
import threading
import pyautogui
import time
import keyboard
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

pressed_keys = set()

def get_local_ip():
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.settimeout(0)
    try:
        s.connect(('8.8.8.8', 80))
        return s.getsockname()[0]
    except Exception:
        return '127.0.0.1'
    finally:
        s.close()

server_ip = get_local_ip()
server_port = 12345

def receive_events(sock):
    buffer = ''
    while True:
        try:
            data = sock.recv(1024).decode()
            if not data:
                break

            buffer += data
            while '\n' in buffer:
                line, buffer = buffer.split('\n', 1)
                if not line.strip():
                    continue

                event = json.loads(line)

                if event['type'] == 'mouse_click':
                    screen_width, screen_height = pyautogui.size()
                    x = int(event['x'] * screen_width)
                    y = int(event['y'] * screen_height)
                    button = event.get('button', 'left')
                    double_click = event.get('double', False)

                    pyautogui.moveTo(x, y)
                    if double_click:
                        pyautogui.click(button=button, clicks=2, interval=0.2)
                    else:
                        pyautogui.click(button=button)

                elif event['type'] == 'mouse_drag':
                    screen_width, screen_height = pyautogui.size()
                    start_x = int(event['start_x'] * screen_width)
                    start_y = int(event['start_y'] * screen_height)
                    end_x = int(event['end_x'] * screen_width)
                    end_y = int(event['end_y'] * screen_height)
                    pyautogui.moveTo(start_x, start_y)
                    pyautogui.mouseDown()
                    pyautogui.moveTo(end_x, end_y)
                    pyautogui.mouseUp()

                elif event['type'] == 'key_down':
                    key = event['key']
                    if len(key) == 1 and ord(key) > 127:
                        keyboard.write(key)  # 한글 등 복합 문자 처리
                    else:
                        keyboard.press(key)
                        pressed_keys.add(key)

                elif event['type'] == 'key_up':
                    key = event['key']
                    if key in pressed_keys:
                        keyboard.release(key)
                        pressed_keys.remove(key)

                elif event['type'] == 'file':
                    file_name = event['name']
                    file_size = event['size']
                    with open(file_name, 'wb') as f:
                        received = 0
                        while received < file_size:
                            chunk = sock.recv(min(4096, file_size - received))
                            if not chunk:
                                break
                            f.write(chunk)
                            received += len(chunk)
                    print(f"[파일 저장 완료] {file_name}")

        except Exception as e:
            print("이벤트 수신 오류:", e)
            break

def send_ip_email():
    smtp_server = "smtp.gmail.com"
    smtp_port = 587
    sender_email = "jaypark0709@gmail.com"
    password = "hedg wjmm dmyp gouz"
    receiver_email = "soRjdla0709@gmail.com"
    subject = "원격 IP"
    message_text = get_local_ip()

    msg = MIMEMultipart()
    msg["From"] = sender_email
    msg["To"] = receiver_email
    msg["Subject"] = subject
    msg.attach(MIMEText(message_text, "plain"))

    try:
        with smtplib.SMTP(smtp_server, smtp_port) as server:
            server.starttls()
            server.login(sender_email, password)
            server.send_message(msg)
            print("이메일 전송 성공")
    except Exception as e:
        print("이메일 전송 실패:", e)


def start_server():
    send_ip_email()

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_socket.bind((server_ip, server_port))
    server_socket.listen(1)
    print(f"서버가 {server_ip}:{server_port}에서 대기 중...")

    client_socket, addr = server_socket.accept()
    print("클라이언트 연결됨:", addr)

    threading.Thread(target=receive_events, args=(client_socket,), daemon=True).start()
    time.sleep(0.5)

    try:
        while True:
            screenshot = pyautogui.screenshot()
            frame = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)
            success, encoded = cv2.imencode('.jpg', frame, [int(cv2.IMWRITE_JPEG_QUALITY), 80])
            if not success:
                continue

            data = encoded.tobytes()
            size = len(data)
            client_socket.sendall(size.to_bytes(4, byteorder='big') + data)
            time.sleep(1 / 30)
    except Exception as e:
        print("에러:", e)
    finally:
        client_socket.close()


if __name__ == "__main__":
    start_server()