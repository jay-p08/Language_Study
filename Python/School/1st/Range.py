if __name__ == "__main__" :
    num1, num2 = map( int, input( "정수1, 정수2 입력 >>> " ).split() )
    sum = 0
    for i in range( num1, num2+1 ) :
        sum += i
    print( sum )