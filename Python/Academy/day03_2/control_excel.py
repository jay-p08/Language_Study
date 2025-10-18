import openpyxl

def save_excel() :
    # 엑셀 워크북 객체 생성
    wb = openpyxl.Workbook()

    # 워크북의 활성화된 시트를 변수에 담는다.
    sheet = wb.active

    # 시트의 좌표에 값을 담는다. -> 마치 dict자료형처럼
    sheet[ "A1" ] = "이름"
    sheet[ "B1" ] = "나이"
    sheet[ "A2" ] = "홍길동"
    sheet[ "B2" ] = 30

    # 워크북을 파일로 저장
    wb.save( "example.xlsx" )

def load_excel() :
    # 엑셀 파일 경로를 통해 워크북 객체 읽어오기
    wb = openpyxl.load_workbook( "example.xlsx" )

    # 활성화된 시트 변수에 담아서 쓰기
    sheet = wb.active

    # 시트의 좌표를 통해 값을 가져오기
    print( sheet[ "A2" ].value ) # 홍길동

if __name__ == "__main__" :
    # 엑셀에 내용을 출력하는 함수
    # save_excel()

    # 엑셀에서 내용을 읽어오는 함수
    load_excel()