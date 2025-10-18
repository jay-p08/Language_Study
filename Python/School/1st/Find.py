if __name__ == "__main__" :
    Number = [ 1, 2, 3, 4, 5, 6, 7 ]
    input = int(input( "입력 >>> " ))
    count = 0
    
    for i in range( input ) :
        count+=1
        if Number[i] == input :
            temp = i
            break
    del( Number[temp] )

    print( "인덱스 번호 :", temp, "리스트 :", Number )