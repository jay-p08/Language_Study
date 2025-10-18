if __name__ == "__main__" :
    str = "ABCDEFGHIJ"
    for i in range(1, len( str )+1) :
        if i%2 == 0 :
            print( str[-i], end="" )