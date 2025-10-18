# 선택 정렬 알고리즘 함수로 구현하기
# 시간 복잡도를 측정하기 위해 time 라이브러리 임포트
import time

# 선택 정렬 함수
def selection_sort( arr: list ):
    # 리스트의 길이를 변수에 담는다.
    n = len( arr )

    # 정렬 시작 전 타임 스탬프 변수에 현재 시간 저장
    start = time.time()

    # 정렬 시작
    for x in range( n ) :
        # 현재 위치를 최소값의 인덱스로 초기화
        min_idx = x
        # x + 1 부터 끝까지 순회하며 최소값 찾기
        for y in range( x + 1, n ) :
            if arr[ y ] < arr[ min_idx ] :
                min_idx = y
        # 현재 위치의 원소와 찾은 쇠초값을 교환
        arr[ x ], arr[ min_idx ] = arr[ min_idx ], arr[ x ]

    

    # 정렬 끝, 현재시간 저장
    end = time.time()

    # 정렬하는 데 걸린 시간 출력
    print( f"걸린 시간: { end - start }" )

    # 전달받은 리스트 객체를 직접 수정해서
    # 반환한다.
    return arr

if __name__ == "__main__" :
    import random
    data = [ e for e in range( 20000 ) ]
    random.shuffle( data )
    result = selection_sort( data )
    print( result )