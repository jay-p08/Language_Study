if __name__ == "__main__" :
    input = int( input( "점수 입력 : " ) )
    rank = ' '
    
    if input >= 90 :
        rank = 'A'
    elif input >= 80 :
        rank = 'B'
    elif input >= 70 :
        rank = 'C'
    else : rank = 'X'

    print( rank )