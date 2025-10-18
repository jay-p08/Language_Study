# 슈팅
import pygame.surface
import pygame
import random

class Enemy( pygame.sprite.Sprite ) :
    def __init__( self ) :
        super().__init__()

        # 적 이미지와 초기 위치 설정
        self.image = pygame.surface( ( 40, 40 ) )
        self.image.fill( ( 255, 0, 0 ) ) # 빨간색으로 설정

        self.rect = self.image.get_rect()

        self.generate()

    def generate( self, change_speed : bool = True ) :
        self.rect.x = random.randrange( 0, 760 )
        self.rect.y = random.randrange( -100, -40 )

        if change_speed : # 속도를 바꾸어서 
            # 랜덤한 이동 속도 설정
            self.speedy = random.randrange( 1, 2 )

    def update( self ) :
        # 적 우주선을 아래로 이동
        self.rect.y += self.speedy
        
        # 화면 아래로 나가면 다시 위에서 시작
        if self.rect.top > 600 :
            self.generate( False )