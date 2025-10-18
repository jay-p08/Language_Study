import time, keyboard, pyautogui, threading, json, cv2, socket, smtplib, numpy
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

pressed_keys = set()

def receive_events(sock):
    buffer = ''
    while True:
        try:
            data = sock.recv(1024).decode()
            if not data:
                time.sleep(0.1)
                continue
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

                    print(f"[클릭 이벤트 수신] 위치: ({x}, {y}), 버튼: {button}")
                    pyautogui.moveTo(x, y)
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
                        keyboard.write(key)
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
            try:
                sock.close()
            except:
                pass
            break

def get_local_ip():
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    try:
        s.connect(('8.8.8.8', 80))
        local_ip = s.getsockname()[0]
    except Exception:
        local_ip = '127.0.0.1'
    finally:
        s.close()
    return local_ip

# 이메일 보내기
def send_ip_email():
    smtp_server = "smtp.gmail.com"
    smtp_port = 587
    sender_email = "jaypark0709@gmail.com"
    password = "hedg wjmm dmyp gouz"  # 보안상 주의 필요
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

# 클라이언트 처리
def handle_client(sock, addr):
    print("클라이언트 연결됨:", addr)
    threading.Thread(target=receive_events, args=(sock,), daemon=True).start()

    try:
        while True:
            screenshot = pyautogui.screenshot()
            frame = cv2.cvtColor(numpy.array(screenshot), cv2.COLOR_RGB2BGR)
            success, encoded = cv2.imencode('.jpg', frame, [int(cv2.IMWRITE_JPEG_QUALITY), 80])
            if not success:
                continue
            data = encoded.tobytes()
            sock.sendall(len(data).to_bytes(4, 'big') + data)
            time.sleep(1 / 30)
    except Exception as e:
        print(f"[{addr}] 연결 종료:", e)
        try:
            sock.close()
        except:
            pass

# 메인 서버 실행
def start_server():
    send_ip_email()
    server_ip = get_local_ip()
    server_port = 12345

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_socket.bind((server_ip, server_port))
    server_socket.listen(5)
    print(f"서버가 {server_ip}:{server_port} 에서 대기 중...")

    while True:
        try:
            client_socket, addr = server_socket.accept()
            client_socket.settimeout(None)
            threading.Thread(target=handle_client, args=(client_socket, addr), daemon=True).start()
        except Exception as e:
            print("서버 accept 오류:", e)
            time.sleep(1)

if __name__ == "__main__":
    start_server()
