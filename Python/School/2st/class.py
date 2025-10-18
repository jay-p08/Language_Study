class Card :
    number = 0
    kind = 0
    def __init__( self, number, kind ):
        self.number = number
        self.kind = kind
    def print( self ) :
        if self.number < 1 and self.number > 13 :
            print( "경고" )
        if self.kind != "heart" or self.kind != "diamond" or self.kind != "club" or self.kind != "spade" :
            print( "경고" )
        print( "숫자 : ", self.number, "문양 : ", self.kind )

if __name__ == "__main__" :
    card = Card( 14, "spade" )
    card.print()