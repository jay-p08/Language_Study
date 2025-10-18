if __name__ == "__main__":
    input = int( input( "입력 >> " ) )
    if input % 2 == 0 :
        input -= 1
    # if
    num = input // 2
    print( num )
        
    for i in range( num ):
        print( "*" * ( i + 1 ) + " " * ( input - ( 2 * ( i + 1 ) ) ) + "*" * ( i + 1 ) )
    # for

    print( "*" * input )
        
    for i in range( num ):
        print( "*" * ( num - i ) + " " * ( 2 * i + 1 ) + "*" * ( num - i ) )
    # for
# main