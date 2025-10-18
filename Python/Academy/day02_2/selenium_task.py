# 셀레니움을 활용한 웹 크롤링
# 웹 브라우저를 드라이버를 이용하여
# 코드로 직접 조작하며 그 결과를 눈으로 확인할 수 있다.

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

# 키워드를 입력받아서, 해당 키워드로 지마켓에 검색하는 메서드
def set_url( keyword : str = "청바지" ) :
    # 전달받은 키워드로 검색한 페이지 경로를 설정하는 부분
    link = f"https://www.gmarket.co.kr/n/search?keyword={keyword}"
    # 크롬 브라우저를 드라이버를 이용해 실행하는 부분
    driver = webdriver.Chrome()
    # 실행한 자동화 브라우저에 링크를 전달하여 이동하는 부분
    driver.get( link )

    # # 어떤 속성을 가져올 것인지,
    # # 해당 속성의 값이 어떨 때 가져올 것인지
    # target = ( By.CLASS_NAME, "text__value" )
    # # 해당되는 태그 요소를 모두 들고오는 함수
    # # find_elements()
    # result = driver.find_elements( target[0], target[1] )
    # for e in result :
    #     print( e.text )

    # id 값으로 요소 하나 들고 오기
    element = driver.find_element( By.ID, "item_" )
    print( element.text )

if __name__ == "__main__" :
    set_url()
