if __name__ == "__main__" :
    index = int( input( "층 수 >>> " ) )
    min = 1
    max = 0

    for i in range( index+1 ) :
        print( (index-i) * "\t", end="")
        for j in range( i ) :
            print( min, end = " " )
            max = min
            min += j+2
        min = 1
        print()
    
    print( "---마지막 층 최소, 최대값---" )
    print( "최대값 :", max )
    print( "최소값 :", min )