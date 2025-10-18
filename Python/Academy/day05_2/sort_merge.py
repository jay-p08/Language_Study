# 병합 정렬( merge sort )
# 리스트를 절반으로 나누어 각 부분 리스트를
# 재귀적으로 정렬한다.

# 병합 정렬 함수 선언
def merge_sort( arr ) :
    # 기본케이스 : 리스트의 길이가 1이하라면 그대로 반환한다.
    if len( arr ) <= 1 : return arr

    # 리스트를 두 부분으로 나눈다.
    mid = len( arr ) // 2
    left = merge_sort( arr[ : mid ] ) # 왼쪽 부분 리스트를 재귀적으로 정렬
    right = merge_sort( arr[ mid : ] ) # 오른쪽 부분 리스트를 재귀적으로 정렬

    # 정렬된 두 부분 리스트를 병합하는 함수 호출
    return merge( left, right )

def merge( left, right ) :
    # 반환할 리스트를 담을 result 변수 선언
    result = []
    x, y = 0, 0 # 반복횟수를 담을 인덱스 변수 초기화
    # x와 y를 증가시킬 건데,
    # 그 값이 좌우 리스트의 길이보다 작은 동안에만
    # 반복을 시행
    while x < len( left ) and y < len( right ) :
        # 두 리스트를 비교하며 작은 값을 result에 추가
        if left[ x ] <= right[ y ] :
            # 왼쪽 리스트의 x번째 값이 오른쪽 리스트의 y번째 값보다 작으면
            # 작은 쪽을 result에 추가
            result.append( left[ x ] )
            x += 1
        else :
            result.append( right[ y ] )
            y += 1
    # 두 리스트의 길이 중 하나에 x 혹은 y가 도달하면
    # 반복문을 탈출한다.
    # 그러면 남은 요소들이 있을 텐데,
    # 이런 남은 요소를 result에 추가
    result.extend( left[ x : ] )
    result.extend( right[ y : ] )
    return result

if __name__ == "__main__" :
    import random
    arr = [ x for x in range( 10 ) ]
    random.shuffle( arr )
    print( arr )

    result = merge_sort( arr )
    print( result )