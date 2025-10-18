if __name__ == "__main__" :
    cnt = 0
    for i in range( 1, 100+1 ) :
        for j in range( 2 ) :
            try :
                if str(i)[j] == "3" or str(i)[j] == "6" or str(i)[j] == "9" :
                    cnt+=1
            except IndexError :
                pass

    print( "박수 친 횟수 :", cnt )