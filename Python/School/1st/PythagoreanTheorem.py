import random as r

if __name__ == "__main__" :
    a, b, c = 0, 0, 0 # 80 150 170
    while True :
        print( a, b, c )
        if a < b and b < c :
            if ( a^2 + b^2 ) == c^2 :
                if a + b + c == 400 :
                    print( "==============" )
                    print( a, b, c ); break
        a = r.randrange( 1, 100 )
        b = r.randrange( 1, 200 )
        c = r.randrange( 1, 300 )