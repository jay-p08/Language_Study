class Faction :
    def __init__( self, numerator, denominator ) :
        self.numerator = numerator
        self.denominator = denominator

    def set_numerator( self, numerator ) :
        self.numerator = numerator

    def set_denominator( self, denominator ) :
        self.denominator = denominator

    def add( self, faction ) :
        if( self.denominator == faction.denominator ) :
            return Faction( self.numerator + faction.numerator, self.denominator )
    
    def sub( self, faction ) :
        if( self.denominator == faction.denominator ) :
            return Faction( self.numerator - faction.numerator, self.denominator )
    
    def __str__( self ) :
        return f"{self.numerator} / {self.denominator}"
    
if __name__ == "__main__" :
    faction1 = Faction( 2, 5 )
    faction2 = Faction( 1, 5 )

    faction3 = faction1.add( faction2 )
    faction4 = faction1.sub( faction2 )
    print( faction3 )
    print( faction4 )