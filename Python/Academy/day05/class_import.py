# import
# import는 현재 작성중인 파일과
# 같은 폴더 내에 있는 다른 파일(모듈)을 가져오는 방법이다.
# 이때, 해당 파일(모듈) 전체가 아니라
# 그 모듈 내의 요소(함수, 클래스, 변수, 상수)만
# 들고 오고 싶다면,
from class_task import Student as St1
# from 에 모듈명을 적고
# import에 가져오고자 하는 요소를 적어서
# 가져올 수 있다.
from class_basic import Person as St2
# 만약 가져온 요소의 이름을
# 다른 이름으로 부르고 싶다면
# as를 사용하여 별칭을 부여할 수 있다.

if __name__ == "__main__" :
    kim2 = St1(10, 20, 30)
    print(kim2.get_math())