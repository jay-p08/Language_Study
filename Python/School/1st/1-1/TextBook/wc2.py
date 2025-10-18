if __name__ == "__main__" : 
    def wc2( str ) :
        strCount, chCount, spCount = 1, 0, 0
        for x in str :
            if( x == " " ) : 
                spCount += 1
                strCount += 1
            chCount += 1
        return ( strCount, chCount - spCount, spCount )

    print( wc2( "abcd ef g da" ) )