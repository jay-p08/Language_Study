# json 파일 입출력
# json은 dict 자료구조와 동일한 방식으로,
# 키값과 value값으로 이루어져 있다.
import json

def write_json(file_path = None, data:dict = None) :
    file_path = file_path or input("파일 드래그") or "test.json"

    data = data or {
        "이름" : "홍길동",
        "나이" : 30,
        "직업" : "개발자",
        "점수" : {
            "수학" : 80,
            "국어" : 90,
            "영어" : 75,
        },
    }
    
    # json 파일 쓰기
    with open(file_path, "w", encoding = "utf-8-sig") as f :
        json.dump(data, f, ensure_ascii = False, indent = 4)

def read_json(file_path = None) :
    file_path = file_path or input("파일 드래그") or "test.json"
    
    data = None
    # 파일 읽어오기
    with open(file_path, "r", encoding = "utf-8-sig") as f:
        data = json.load(f)

    return data

if __name__ == "__main__" :
    # write_json()
    data = read_json()
    print(data) 