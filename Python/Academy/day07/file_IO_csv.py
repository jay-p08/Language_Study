# csv 파일 입출력
# 데이터를 전송하기 위한 파일 형식 중 하나로,
# 테이블(행과 열로 이루어진 표 데이터) 형식으로 만들어져있다.
# 이때, 한 행의 값들은 반점(,)를 구분자로 하여 값이 구분되어 있으며,
# 이 때문에 Comma Seperate Values의 준말로 vcsv라고 부르는 것이다.

# 이러한 csv를 파이썬에서 다루려면
# 관련 라이브러리를 임포트해야 한다.
import csv

def write_csv(file_path = None) :
    file_path = file_path or input("파일명을 입력해 주세요.\n") or "temp.csv"
    with open(file_path, "w", newline = "", encoding = "utf-8-sig") as f : 
        # csv 파일을 텍스트 파일이나 엑셀같은 다른 프로그램으로 읽을 때
        # 모두 한글로 정상적으로 읽으려면
        # 인코딩을 utf-8-sig 방식으로 해야 한다.
        writer = csv.writer(f)
        writer.writerow(["이름", "나이", "직업"])
        writer.writerow(["박재영", "17", "학생"])
        writer.writerow(["박민준", "40", "디자이너"])

def read_csv(file_path = None) :
    file_path = file_path or input("파일명을 입력해 주세요.\n") or "temp.csv"
    rows = list()
    with open(file_path, "r", newline = "", encoding = "utf-8-sig") as f :
        reader = csv.reader(f)
        rows = list(reader)
    return rows

if __name__ == "__main__" :
    # write_csv()
    rows = read_csv()
    for row in rows :
        # print(row)
        for col in row :
            print(col, end = " | ")
        print(" ")