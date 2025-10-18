# 삽입_정렬( insertion sort )
# 우측의정렬이 안 된 부분의 값을
# key에임시로 담아두고
# 좌측의 정렬된 값과 비교하여
# 좌측의 값을 우측으로 한 칸 미룰지
# 혹은 key값이 좌측의 값보다 크다면
# 현재 위치에 key 값을 삽입하는 방식
# -> 정렬하고자 하는 값( key )을
# 정렬된 부분의 적절한 위치에 삽입하는 정렬 알고리즘
def insertion_sort( arr ) :
    print( arr ) # 초기 상태 출력
    # 1번쨰부터 arr의 길이-1번째까지의 요소를 접근
    # 왜 1번째? 0번째는 이미 정렬된 값이라고 간주한다.
    for x in range( 1, len( arr ) ) :
        # 정렬이필요한 숫자( 삽입 대상 값 )
        current = arr[ x ]
        # 현재 삽입할 인덱스의 이전 인덱스
        before_idx = x - 1

        # 현재 삽입 대상보다 큰 숫자들을 오른쪽으로 한칸씩 이동
        while before_idx >= 0 and current < arr[ before_idx ] :
            # 이전 인덱스가 0보다 크거나 같고
            # 현재 삽입하려는 값이 이전 값보다 적다면
            # 이전 인덱스의 값을 우측으로 1칸 이동
            arr[ before_idx + 1 ] = arr[ before_idx ]
            before_idx -= 1
        arr[ before_idx + 1 ] = current
        # 한번 정렬이 끝날 때마다 정렬 상태 확인
        print( arr[ : before_idx + 1 ] )

    return arr

import random

if __name__ == "__main__" :
    random.shuffle( arr := [ x for x in range( 10 ) ] )
    insertion_sort( arr )