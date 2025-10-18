# 클래스를 작성하고
# __len__ 매직 메서드 재정의
# len()을 이용하여 원하는 값 받아오기

class String_to_list() :
    def __init__(self, value) -> None: # value : "홍길동"
        self.value : list = list(str(value))
        print(self.value) # ["홍", "길", "동"]

    # __len__ 매직 메서드 정의하기
    def __len__(self) :
        result = 0
        result = len(self.value)
        return result
    
    # 인덱스/키로 접근 시
    def __getitem__(self, key:int) :
        return self.value[key]
    
    def __setitem__(self, key, value) :
        print(key)
        print(value)
        self.value[key] = value
        
if __name__ == "__main__" :
    obj = String_to_list(1024)
    # print(len(obj)) # 4
    # print(obj[1]) # 0
    obj[4] = "홍"