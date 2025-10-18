import socket
from tkinterdnd2 import DND_FILES, TkinterDnD
import os
import json
import tkinter as tk
import numpy as np
import cv2
from PIL import ImageTk, Image

server_ip = "10.96.120.98"
server_port = 12345

# 상단에 전역 변수 추가
offset_x = 0
offset_y = 0
new_width = 0
new_height = 0

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((server_ip, 12345))

root = tk.Tk()
screen_width = root.winfo_screenwidth()
screen_height = root.winfo_screenheight()
root.geometry(f"{screen_width}x{screen_height}")
label = tk.Label(root)
label.pack()

# 클릭, 드래그 좌표 보정 함수
def normalize_coords(event):
    global offset_x, offset_y, new_width, new_height
    x = (event.x - offset_x) / new_width
    y = (event.y - offset_y) / new_height
    return x, y

def send_file(path):
    file_name = os.path.basename(path)
    file_size = os.path.getsize(path)

    # 1. 파일 전송 신호
    message = {
        "type": "file",
        "name": file_name,
        "size": file_size
    }
    client_socket.sendall((json.dumps(message) + "\n").encode())

    # 2. 실제 파일 전송
    with open(path, "rb") as f:
        while chunk := f.read(4096):
            client_socket.sendall(chunk)

def send_click(event, double=False):
    x, y = normalize_coords(event)
    if 0 <= x <= 1 and 0 <= y <= 1:
        message = {
            "type": "mouse_click",
            "x": x,
            "y": y,
            "button": "left",
            "double": double
        }
        client_socket.send((json.dumps(message) + "\n").encode('utf-8'))

def on_single_click(event):
    send_click(event, double=False)

# 더블 클릭
def on_double_click(event):
    send_click(event, double=True)

drag_start = None  # 드래그 시작점 저장용 변수

def on_mouse_down(event):
    global drag_start
    x, y = normalize_coords(event)
    if 0 <= x <= 1 and 0 <= y <= 1:
        drag_start = (x, y)

def on_mouse_drag(event):
    if drag_start:
        end_x, end_y = normalize_coords(event)
        if 0 <= end_x <= 1 and 0 <= end_y <= 1:
            message = {
                "type": "mouse_drag",
                "start_x": drag_start[0],
                "start_y": drag_start[1],
                "end_x": end_x,
                "end_y": end_y,
                "button": "left"
            }
            client_socket.send((json.dumps(message) + "\n").encode('utf-8'))

def on_mouse_up(event):
    global drag_start
    drag_start = None

def on_key_press(event):
    key = event.char if event.char else event.keysym
    message = {
        "type": "key_down",
        "key": key
    }
    client_socket.send((json.dumps(message) + "\n").encode('utf-8'))

def on_key_release(event):
    key = event.char if event.char else event.keysym
    message = {
        "type": "key_up",
        "key": key
    }
    client_socket.send((json.dumps(message) + "\n").encode('utf-8'))

# 기존 바인딩 + 키보드 바인딩 추가
label.bind("<Button-1>", on_single_click)
label.bind("<Double-Button-1>", on_double_click)
label.bind("<ButtonPress-1>", on_mouse_down)
label.bind("<B1-Motion>", on_mouse_drag)
label.bind("<ButtonRelease-1>", on_mouse_up)
root.bind("<KeyPress>", on_key_press)
root.bind("<KeyRelease>", on_key_release)  # 추가된 키보드 release 이벤트

def update_frame():
    global offset_x, offset_y, new_width, new_height
    try:
        size_data = client_socket.recv(4)
        if not size_data:
            root.destroy()
            return
        size = int.from_bytes(size_data, byteorder='big')

        buffer = b''
        while len(buffer) < size:
            packet = client_socket.recv(size - len(buffer))
            if not packet:
                root.destroy()
                return
            buffer += packet

        nparr = np.frombuffer(buffer, np.uint8)
        frame = cv2.imdecode(nparr, cv2.IMREAD_COLOR)
        img = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

        # 비율 유지 리사이즈 + 중앙 정렬
        frame_height, frame_width = img.shape[:2]
        scale = min(screen_width / frame_width, screen_height / frame_height)
        new_width = int(frame_width * scale)
        new_height = int(frame_height * scale)
        resized = cv2.resize(img, (new_width, new_height))

        offset_x = (screen_width - new_width) // 2
        offset_y = (screen_height - new_height) // 2

        final_img = np.ones((screen_height, screen_width, 3), dtype=np.uint8) * 255
        final_img[offset_y:offset_y + new_height, offset_x:offset_x + new_width] = resized

        img_pil = ImageTk.PhotoImage(Image.fromarray(final_img))
        label.config(image=img_pil)
        label.image = img_pil

    except Exception as e:
        print("에러:", e)
        root.destroy()
        return

    root.after(10, update_frame)

update_frame()
root.focus_set()
root.mainloop()