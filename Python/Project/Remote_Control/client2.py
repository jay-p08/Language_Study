import cv2, os, json, socket, numpy, tkinter, time
from PIL import ImageTk, Image
from tkinterdnd2 import DND_FILES, TkinterDnD

# 서버 설정
server_ip = "10.96.120.98"  # 서버의 IP 주소
server_port = 12345

# Tkinter 설정
root = TkinterDnD.Tk()
screen_width = root.winfo_screenwidth()
screen_height = root.winfo_screenheight()
root.geometry(f"{screen_width}x{screen_height}")
label = tkinter.Label(root)
label.pack(fill="both", expand=True)

# 전역 위치 정보
offset_x = 0
offset_y = 0
new_width = 0
new_height = 0
drag_start = None
dragging = False
mouse_down_time = 0

# 좌표 정규화
def normalize_coords(event):
    x = (event.x - offset_x) / new_width
    y = (event.y - offset_y) / new_height
    return x, y

# 파일 전송
def send_file(path, sock):
    file_name = os.path.basename(path)
    file_size = os.path.getsize(path)
    header = {"type": "file", "name": file_name, "size": file_size}
    sock.sendall((json.dumps(header) + "\n").encode())
    with open(path, "rb") as f:
        while chunk := f.read(4096):
            sock.sendall(chunk)

# 마우스 이벤트
def on_mouse_down(event, sock):
    global drag_start, mouse_down_time, dragging
    x, y = normalize_coords(event)
    if 0 <= x <= 1 and 0 <= y <= 1:
        drag_start = (x, y)
        mouse_down_time = time.time()
        dragging = False

def on_mouse_drag(event, sock):
    global drag_start, dragging
    if drag_start:
        end_x, end_y = normalize_coords(event)
        if 0 <= end_x <= 1 and 0 <= end_y <= 1:
            dragging = True
            msg = {
                "type": "mouse_drag",
                "start_x": drag_start[0],
                "start_y": drag_start[1],
                "end_x": end_x,
                "end_y": end_y,
                "button": "left"
            }
            sock.sendall((json.dumps(msg) + "\n").encode())
            drag_start = (end_x, end_y)

def on_mouse_up(event, sock):
    global drag_start, dragging, mouse_down_time
    if not dragging:
        elapsed = time.time() - mouse_down_time
        if elapsed < 0.3:  # 클릭으로 판단
            x, y = normalize_coords(event)
            if 0 <= x <= 1 and 0 <= y <= 1:
                msg = {"type": "mouse_click", "x": x, "y": y, "button": "left"}
                sock.sendall((json.dumps(msg) + "\n").encode())
    drag_start = None
    dragging = False

# 키보드 이벤트
def on_key_down(event, sock):
    msg = {"type": "key_down", "key": event.keysym}
    sock.sendall((json.dumps(msg) + "\n").encode())

def on_key_up(event, sock):
    msg = {"type": "key_up", "key": event.keysym}
    sock.sendall((json.dumps(msg) + "\n").encode())

# 드래그 앤 드롭 이벤트
def on_drop(event, sock):
    paths = root.tk.splitlist(event.data)
    for path in paths:
        if os.path.isfile(path):
            send_file(path, sock)

# 프레임 수신
def update_frame(sock):
    global offset_x, offset_y, new_width, new_height
    try:
        size_data = sock.recv(4)
        if not size_data:
            root.destroy()
            return
        size = int.from_bytes(size_data, byteorder='big')
        buffer = b''
        while len(buffer) < size:
            packet = sock.recv(size - len(buffer))
            if not packet:
                root.destroy()
                return
            buffer += packet

        nparr = numpy.frombuffer(buffer, numpy.uint8)
        frame = cv2.imdecode(nparr, cv2.IMREAD_COLOR)
        img = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

        # 중앙 정렬 및 비율 유지
        frame_h, frame_w = img.shape[:2]
        scale = min(screen_width / frame_w, screen_height / frame_h)
        new_width, new_height = int(frame_w * scale), int(frame_h * scale)
        resized = cv2.resize(img, (new_width, new_height))
        offset_x = (screen_width - new_width) // 2
        offset_y = (screen_height - new_height) // 2

        # Pillow 기반으로 중앙 정렬된 이미지 생성
        pil_base = Image.new("RGB", (screen_width, screen_height), (255, 255, 255))
        pil_resized = Image.fromarray(resized)
        pil_base.paste(pil_resized, (offset_x, offset_y))

        img_pil = ImageTk.PhotoImage(pil_base)
        label.config(image=img_pil)
        label.image = img_pil

    except Exception as e:
        print("프레임 수신 오류:", e)
        root.destroy()
        return

    if root.winfo_exists():
        root.after(10, lambda: update_frame(sock))

# 메인 함수
def main():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((server_ip, server_port))

    # 이벤트 바인딩
    label.bind("<ButtonPress-1>", lambda e: on_mouse_down(e, sock))
    label.bind("<B1-Motion>", lambda e: on_mouse_drag(e, sock))
    label.bind("<ButtonRelease-1>", lambda e: on_mouse_up(e, sock))
    root.bind("<KeyPress>", lambda e: on_key_down(e, sock))
    root.bind("<KeyRelease>", lambda e: on_key_up(e, sock))
    root.drop_target_register(DND_FILES)
    root.dnd_bind('<<Drop>>', lambda e: on_drop(e, sock))

    update_frame(sock)
    if root.winfo_exists():
        try:
            root.focus_set()
        except:
            pass
    root.mainloop()

if __name__ == "__main__":
    main()