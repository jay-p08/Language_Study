# 버블 정렬
# 0번째부터 n번째까지 인접한 요소끼리 비교하여
# 정렬하고자 한느 순서와 맞지 않으면
# 두 요소의 자리를 바꾸는 방식으로
# 전체 요소들을 우측에 가장 큰 값부터 정렬하는 방식으로 동작한다.
# 때문에 매 반복( 패스 )이 끝날 때마다
# 가장 우측은 정렬이 끝났기 때문에
# 우측의 패스 횟수 만큼은 검사할 필요가 없다( 이미 정렬되어 있으니까 )

def bubble_sort( arr ) :
    # 전달받은 arr의 길이를 n 변수에 담는다.
    n = len( arr )
    # 처음 arr 상태 출력
    print( arr )

    # arr의 길이 만큼 외부 반복을 시행한다.
    for x in range( n ) :
        # 외부 반복( 패스 )을 시행했을 때, 교환이 일어나지 않았다면
        # 모두 정렬된 상태라는 의미이므로
        # 조기 종료한다.
        # 교환이 일어났는지 여부를 담을 변수 선언 및
        # 패스 시작 시 False로 초기화
        swapped = False

        # 내부 반복으로, 인접한 요소끼리 비교하고 교환하는 부분
        for y in range( n - 1 ) : # 0부터 n - 1번째까지 반복해야
            # n - 1과 n번째를 마지막으로 비교하여 리스트의 길이를 벗어나는 오류를 범하지 않는다.
            # 인접한( y번째와 y + 1번째 ) 요소를 비교하여 순서가 다르면
            # 교환한다.
            if arr[ y ] > arr[ y + 1 ] : # j번째가 큰 값이면 j + 1과 그 위치를 교환한다.
                arr[ y ], arr[ y + 1 ] = arr[ y + 1 ], arr[ y ]
                swapped = True
        print( arr )
        if swapped is False : # 교환이 일어나지 않았다면
            # 이미 전체 정렬된 상태라는 의미이므로
            break # 조기종료

    return arr

import random

if __name__ == "__main__" :
    # 0부터 99까지의숫자를 담은 리스트를
    # arr에 담으면서 동시에 섞는 코드
    random.shuffle( arr := [ x for x in range( 10 ) ] )
    bubble_sort( arr )