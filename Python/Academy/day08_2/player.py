# player.py
import pygame.key
import pygame

class Player( pygame.sprite.Sprite ) :
    def __init__( self ) :
        super().__init__()
        
        # 객체를 그린다
        self.image = pygame.Surface( ( 50, 50 ) )
        # 초록색으로 객체 변경
        self.image.fill( ( 0, 255, 0 ) )
        # 객체
        self.rect = self.image.get_rect()
        self.rect.centerx = ( 400, 550 )
    
    # 스프라이트 객체라면 모두가 구현해야 하는 메서드로
    # 화면에서 그려질 때, 실행될 내용을 적는 공간
    def update( self ) :
        self.move()

    def move( self ) :
        # 키보드 입력 감지
        keys = pygame.key.get_pressed()
        # 왼쪽 화살표 키를 누르면 왼쪽으로 이동
        if keys[ pygame.K_LEFT ] and \
            self.rect.left > 0 : # 플레이어가
            self.rect.x -= 2
        if keys[ pygame.K_RIGHT ] and \
            self.rect.right < 800 :
            self.rect.x += 2