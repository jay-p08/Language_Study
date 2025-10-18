# 정규 표현식( Regular Expression )
# 문자열의 패턴을 파악하여 추출하거나 검색, 검사하는 용도로
# 쓰이는 기술이다.
# 쓰임새 : 이메일 형식 검사, 아이디 형식 검사
# 확인하고자 하는 문자열 내에 특정 패턴의 문자열이 있는지 검사

# re 모듈 임포트
import re

def search_string( target_str : str, pattern = r'\d+' ) :
    # target_text에 pattern에 해당하는 문자열이 있다면
    # 해당 문자열을 추출하여 반환하는 함수
    pattern = re.compile( pattern )
    # 검사 하고자 하는 텍스트는 전달하여 해당되는 문자열 추출
    # .findall()
    matches = pattern.findall( target_str )
    return matches

if __name__ == "__main__" :
    target_str = "a2b3c@안-녕1하_세요!2 반.갑3습니4다"
    results = None

    # r'\d+' : 하나의 이상의 숫자를 의미한다
    # results = search_string( target_str, r'\d+' )

    # r'/w+' 하나 이상의 문자를 의미한다
    # \w는 영어, 한글, 숫자, 그리고 언더바_를 가리킨다
    # +는 앞에 오는 문자열이 패턴에 여러글자가 맞으면 하나로 뭉뚱그려서
    # 가져온다
    # +를 안 쓰면 하나씩 가져온다
    # results = search_string( target_str, r'\w+' )
    
    # 반복적으로 등장하는 소문자를 묶어서 추출
    # 반복 혹은 등장
    # * 0번 이상 반복
    # + 1번 이상 반복
    # ? 0번 또는 1번 반복
    # { n } 정확히 n번 반복
    # { n,m } n번 이상 m번이하 반복
        # 주의할 점 : {n,m}의 중괄호 안에서 공백이 있으면 안된다.
    target_str = "aabbabc113aabbc"
    # print( target_str )
    
    # 숫자가 두 개 붙어서 존재하는 것만 추출( ? -> 빈문자여롣 같이 추출됨 )
    # results = search_string( target_str, r'([ 0-9 ]{2})?([ a-z ]{2})?' )
    # 소문자가 두 개 혹은 세 개 붙어서 존재하는 것을 추출
    # 추출된 문자열을 제외하고 2, 3개로 묶을 수 없는 문자가 있으면
    # 무시하고 넘어간다
    # results = search_string( target_str, r'([ a-z ]{2,3})' )

    # 앵커
    # 문자열 내의 특정 위치를 지정한다
    # ^ 문자열의 시작을 나타냄
    # $ 문자열의 끝을 나타냄
    target_str = "135abc152"
    # print( target_str )
    # results = search_string( target_str, r'^[ 0-9 ]+' )

    # 010-1234-5678
    # 전화번호만 추출하고 싶다
    target_str = "010-1234-5678"
    target_str = "010 1234 5678"
    target_str = "01012345678"
    results = search_string( target_str, r'[0-9]{3,4}' )
    results = ''.join( results )

    print( results )