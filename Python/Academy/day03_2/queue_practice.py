# queue를 구현한 클래스 만들기
# 내부적으로 리스트 형태로 구현한다.
# put( data )함수로 새로운 데이터를 뒤에 추가한다.
# get() 함수로 먼저 들어간 값을 반환하고
# 해당 인덱스를 제거한다.
class My_Queue( list ) :
    def __init__( self ) :
        pass

    def put( self, data ) -> None :
        # self, 즉 객체는 list 클래슬르 상속받았기  때문에
        # append() 함수를 이용하여 데이터를 리스트 마지막에
        # 삽입할 수 있다.
        self.append( data )
        return
    
    # get() 함수 구현하기
    # 매개변수는 self만 전달한다.
    # self는 list를 상속받았기 때문에
    # 인덱슬르 ㄹ전달하여 값을 반환하는 pop()함수로
    # 첫번째 요소( 선입선출 )를 pop하여 반환할 것이다.
    def get( self ) :
        # 0번째 요소를 pop하여 반환한다.
        # pop -> 해당 인덱스의 요소를 리스트에서 제거하고
        # 제거된 해당 요소를 반환한다.
        return self.pop( 0 )
    
if __name__ == "__main__" :
    obj = My_Queue()
    obj.put( 30 )
    obj.put( 35 )
    obj.put( 12 )
    print( obj.get() )
    print( obj.get() )
    print( obj.get() )