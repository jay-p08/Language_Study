# 뉴스 크롤링 해보기
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time

class Web_crawling():
    def __init__(self):
        # 크롬 드라이버 초기화
        self.driver = webdriver.Chrome()

    def set_url(self, url:str):
        self.driver.get(url)

    def find_tag(self, type_to_find, type_name):
        # type_to_find는 찾고자 하는 By.~~의 종류를 입력하는 곳
        # type_name은 그렇게 찾고자 하는 타입의 값
        result = self.driver.find_elements(type_to_find, type_name)
        return result

if __name__ == "__main__":
    obj = Web_crawling()
    obj.set_url("https://news.google.com/home")
    result = obj.find_tag(By.TAG_NAME, "a")
    for e in result:
        # if e: # 요소가 비어있지 않다면
        #     print(e.text) # 출력
        if "과학" in e.text:
            e.click()
            break
    time.sleep(5)
    # target = input("찾고자 하는 내용")
    # result = obj.find_tag(By.TAG_NAME, 'a')
    # for e in result:
    #     if e and e.text:
    #         print(e.text)

    elements = obj.find_tag(By.CSS_SELECTOR, 'a.gPFEn')
    datas = list()

    for e in elements:
        if e and e.text:
                data = (e.text, e.get_attribute('href'))
                # print(e.text, e.get_attribute('href'))
                datas.append(data)

    import csv
    file_name = 'it.csv'
    with open(file_name, 'w', newline="", encoding="utf-8-sig") as f:
        writer = csv.writer(f)
        writer.writerow(["제목", "링크"])
        for t, l in datas:
            writer.writerow([t, l])
    