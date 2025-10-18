import os
import sys

def write() :
    file_path = "file.txt"

    with open(file_path, "+a", newline="\n") as file :
        file.write("Hello line1")
        file.write("Hello line1")
        pass
    pass

def read() :
    file_path = "file.txt"
    lines = list()
    try :
        with open(file_path, "r") as file :
            lines = file.readlines()
        return lines
    except FileNotFoundError as e :
        # 파일을 못 찾았을 시 실행할 코드
        print("파일을 찾지 못했습니다.")
        print("예외 : ", e)
    except Exception as e :
        # 기타 예외 처리
        print(f"예상치 못한 오류 발생 : {e}")
    else :
        # 예외가 발생하지 않았을 때 실행할 코드
        print("정상적으로 파일을 읽어왔습니다.")
    finally :
        # 예외 발생 여부와 무관하게 항상 실행할 코드
        print("프로그램 종료")

if __name__ == "__main__" :
    # write()
    result = read()
    # print(result)
    try : # try 구문은 반드시 있어야 한다.
        for line in result :
            print(line.strip("\n"))
    # except 구민이나 finally 구문 중 하나는 반드시 사용해야 한다
    except Exception as e : # 에러 종류를 명시하지 않으면
        # 모든 에러에 대해서 예외처리를 한다.
        print(e)