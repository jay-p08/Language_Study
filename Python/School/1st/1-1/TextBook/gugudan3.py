if __name__ == "__main__" :
    def gugudan3( *dan ) :
        for e in range( len( dan ) ) :
            print( dan[e], "단" )
            for i in range( 1, 9 + 1 ) :
                print( dan[e], "*", i, "=", dan[e] * i )
            print()

    gugudan3( 2, 3, 7 )