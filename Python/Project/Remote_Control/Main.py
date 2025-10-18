import socket
from datetime import datetime

# 타겟 호스트와 포트 범위
target_ip = input("타겟 IP 주소를 입력하세요: ")
start_port = int(input("스캔할 시작 포트를 입력하세요: "))
end_port = int(input("스캔할 끝 포트를 입력하세요: "))

# 타겟 시스템에 연결 시도
print(f"\n[+] {target_ip} 포트 스캔 시작...")
start_time = datetime.now()

# 포트 스캔
for port in range(start_port, end_port + 1):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    result = sock.connect_ex((target_ip, port))
    
    if result == 0:
        print(f"[+] 포트 {port} 열려 있음")
    else:
        print(f"[-] 포트 {port} 닫혀 있음")
    
    sock.close()

end_time = datetime.now()
total_time = end_time - start_time

print(f"\n[+] 포트 스캔 완료. 총 시간: {total_time}")
