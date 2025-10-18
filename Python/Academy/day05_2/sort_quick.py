# 퀵 정렬( quick sort )
# O( n log n )의 시간 복잡도를 가진, 분할 정복 알고리즘의 한 종류이다.
# 퀵 정렬의 핵심은 파벗을 선택하고 이를 기준으로
# 작은 값과 큰 값을 분류하는 것으로 시작한다
# 또한 이를 재귀적으로 실행하는 것이 필연적이다.
def quick_sort( arr ) : # arr은 list를 의미한다.
    # 기본 케이스 : 리스트의 길이가 1보다 작거나 같으면,
    # 정렬이 필요 없으므로 그대로 반환
    if len( arr ) <= 1 : return arr

    # 피벗 선택( 중간 요소를 선택 )
    pivot = arr[ len( arr ) // 2 ]

    # 피벗을 기준으로 세 부분으로 분할
    # 1. 피벗보다 작은 요소들
    left = [ x for x in arr if x < pivot ]

    # 2. 피벗과 같은 요소들
    middle = [ x for x in arr if x == pivot ]

    # 3. 피벗보다 큰 요소들
    right = [ x for x in arr if x > pivot ]

    # 분할된 리스트를 재귀적으로 정렬하고 병합
    return quick_sort( left ) + middle + quick_sort( right )

if __name__ == "__main__" :
    import random

    # 0부터 99까지의 숫자를 생성
    arr = [ x for x in range( 100 ) ]

    # 만들어진 arr을 섞는다
    random.shuffle( arr )

    # 섞인 상태 확인
    print( arr )
    input( "Enter를 누르면 진행" )

    # 정렬 진행
    sorted = quick_sort( arr )

    # 정렬된 상태 확인
    print( sorted )