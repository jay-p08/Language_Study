# stack
# 후입선출
# 나중에 삽입된 데이터가 먼저 나가는 자료구조
# 클래스로 구현해보기

class My_stack(list):
    def __init__(self):
        pass

    # 데이터 삽입 -> 가장 마지막에 요소를 집어넣는다.
    def push(self, data) -> None:
        self.append(data)
        return

    # 마지막 요소를 반환한다.
    def pop(self):
        # -1번째 인덱스를 전달하면 마지막 요소를 반환한다.
        if len(self) > 0: # 저장된 요소의 개수가 0보다 커야 반환
            return super().pop(-1)
        else: # 저장된 요소가 없다면 None 반환
            return None

if __name__ == "__main__":
    obj = My_stack()
    obj.push(1)
    obj.push(2)
    obj.push(3)
    print(obj.pop())
    print(obj.pop())
    print(obj.pop())