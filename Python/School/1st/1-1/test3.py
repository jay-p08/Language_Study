import math

if __name__ == "__main__" :
    IsGame = True
    count = 0
    temp = 0
    sqrt = 1

    while IsGame :
        two = input( "2의 제곱 맞추기 >>> " )
        if two == "end" or count == 50 :
            IsGame = False
        # if
        num = int( two )

        if num == sqrt :
            temp += 1
            sqrt = 2**temp
            print( "정답" )
        # if
        else :
            print( "다시 입력하세요" )
        # else
        count += 1
    # while
# main