if __name__ == "__main__" :
    def gugudan( dan = 2 ) :
        print( dan, "단" )
        for i in range( 1, 9+1 ) :
            print( dan, "*", i, "=", dan * i )
        print()

    gugudan(3)
    gugudan()