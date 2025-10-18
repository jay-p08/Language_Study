import pygame

class Tomagochi :
    def __init__( self, name ) :
        self.MAX_STAT = 100
        self.MIN_STAT = 0
        
        self.name = name
        self.age = 1
        self.fullness = 80
        self.energy = 80
        self.happiness = 80
        self.isDie = False

    def __str__( self ) :
        return f"=================\n이름 >>> { self.name } \n나이 >>> { self.age } \n포만감 >>> { self.fullness } \n에너지 >>> { self.energy } \n행복함 >>> { self.happiness } \n================="

    def update_Setting( self, decrease, dt ) :
        setattr( self, decrease, max( self.MIN_STAT, min( self.MAX_STAT, getattr( self, decrease ) - dt ) ))

    def update( self, dt ) :
        self.update_Setting( 'fullness', 1 * dt )
        self.update_Setting( 'energy', 1.5 * dt )
        self.update_Setting( 'happiness', 1 * dt )

    def setting( self, increase, decrease1, decrease2 ) :
        setattr( self, increase, min( self.MAX_STAT, getattr( self, increase ) + 10 ) )
        setattr( self, decrease1, max( self.MIN_STAT, getattr( self, decrease1 ) - 5 ) )
        setattr( self, decrease2, max( self.MIN_STAT, getattr( self, decrease2 ) - 5 ) )

    def feed( self ) :
        self.setting( 'fullness', 'energy', 'happiness' )

    def sleep( self ) :
        self.setting( 'energy', 'fullness', 'happiness' )

    def play( self ) :
        self.setting( 'happiness', 'fullness', 'energy' )
    
def main( W, H ) :
    pygame.init()
    tomagochi = Tomagochi( "박재영" )
    screen = pygame.display.set_mode( ( W, H ) )
    pygame.display.set_caption( "Tamagochi" )
    UI_Font = pygame.font.SysFont( "Malgun Gothic", 22 )
    clock = pygame.time.Clock()
    tomagochi_Rect = pygame.Rect( W // 2 - 25, H // 2 - 25, 50, 50 )

    running = True
    while running :
        dt = clock.tick( 60 ) / 1000.0
        for event in pygame.event.get() :
            if event.type == pygame.QUIT :
                running = False
            elif event.type == pygame.KEYDOWN :
                if event.key == pygame.K_q :
                    tomagochi.feed()
                if event.key == pygame.K_w :
                    tomagochi.sleep()
                if event.key == pygame.K_e :
                    tomagochi.play()
        tomagochi.update( dt )
        pygame.display.flip()

        print( tomagochi )
    pygame.quit()
    sys.exit()


if __name__ == "__main__" :
    main( 520, 360 )