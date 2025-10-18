class Person :
    def __init__( self, name, age ) :
        self.name = name
        self.age = age
        self.TLNE( self.name )
        self.NAE( self.age )

    def TLNE( self, name ) :
        if len( name ) > 20 :
            raise TooLongNameError
    def NAE( self, age ) :
        if age < 0 :
            raise NegativeAgeError

class TooLongNameError( Exception ) :
    pass

class NegativeAgeError( Exception ) :
    pass

if __name__ == "__main__" :
    try :
        p1 = Person( "123456789012345678901", 18 )
    except TooLongNameError :
        print( "TLNE 에러" )

    try :
        p2 = Person( "12345678901234567890", -1 )
    except NegativeAgeError :
        print( "NAE 에러" )