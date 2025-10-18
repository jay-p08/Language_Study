# un-packing
# 메서드에서 값을 반환할 때.
# 여러 개의 값을 반환하면
# tuple 형태로 packing하여 반환된다.
# 이때, 메서드를 사용한 쪽에서
# 변수에 담으려고 할 때, 반환된 튜플 요소의 개수가
# 담으려는 변수의 개수와 동일하다면
# 순서에 맞게 값이 변수에 각각 담긴다.

def split_name(name:str, len_lastname : int = 1) :
    last_name = name[0:len_lastname] # 성 부분
    first_name = name[len_lastname:] # 이름 부분
    return last_name, first_name

if __name__ == "__main__" :
    성, 이름 = split_name("남궁길동", 2)
    print(f"성 : {성}, 이름 : {이름}")