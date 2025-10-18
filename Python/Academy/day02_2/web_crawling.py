# pip install requests beautifulsoup4 selenium
# 웹 크롤링
# 웹 페이지의 구조를 파악해서, 원하는 위치에 있는 데이터를
# 추출하여 다루는 작업을 웹 크롤링이라고 한다.
# 웹 크롤링은 트래픽을 유발시키기( 웹사이트에 부하를 준다, 손해를 준다. ) 때문에
# 사이트에서 지정해놓은 방식 안에서 활동해야 한다.
# 이를 파악하는 방법은 robots.txt 파일을 확인하는 것이다.
# 예시: https://www.gmarket.co.kr/robots.txt

# 웹크롤링 기초
# 웹 크롤링을 하려면 세 가지 라이브러리가 필요하다
# 1. requests
# 웹 페이지의 내용을 읽어오는 기능
# 그냥 읽어만 오기 때문에, 구조적으로 파악하려면 다른 라이브러리가 필요하다.
# 2. beautifulsoup4
# 읽어온 웹 페이지를 개발자가 읽거나 데이터적으로 접근하기 쉽게
# 내용을 구조화하는 라이브러리다.
# 이를 통해 원하는 데이터를 쉽게 추출할 수 있다.
# 3. selenium
# 동적으로 생성되는 웹 페이지를 크롤링하기 위해서는
# 셀레니움 라이브러리가 유용한다.
# 웹 드라이버를 이용해 웹 브라우저를 코드로 조작하게 도와준다.
# ===================================
import requests
from bs4 import BeautifulSoup as bs

if __name__ == "__main__" :
    url = "https://www.gmarket.co.kr/"
    response = requests.get(url) # url을 통해 접근할 수 있는 웹 페이지 정보를 불러온다.
    # print( response.text )
    # 퓨티풀스프를 통해 html 문서 파싱
    soup = bs( response.text, "html.parser" )
    
    # 모든 div 태그 추출하기
    divs = soup.find_all( "div" )
    
    # 각 div 태그 확인하기
    for div in divs :
        result = div.get( "class" )
        # 클래스 정보가 없다면
        if result is not None :
            print(result)