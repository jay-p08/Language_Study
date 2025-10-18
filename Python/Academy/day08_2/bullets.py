# bullets.py
import pygame

class Bullet( pygame.sprite.Sprite ) :
    def __init__( self, x, y ) :
        super().__init__()
        img_size = ( 5, 10 ) # 가로, 세로
        self.image = pygame.Surface( img_size )
        self.image.fill( ( 255, 255, 0 ) ) # 총알 생상을 노란색

        self.rect = self.image.get_rect()
        self.rect.centor = ( x, y ) # 외부에서 전달받은 좌표에서
        # 총알이 시작하도록 설정

    def update( self ) :
        self.move()

    def move( self ) :
        self.rect.y -= 10 # 총알이 위로 10의 속도로 이동
        # 화면 위 밖으로 나가면 삭제
        if self.rect.bottom < 0 : # 0보다 작으면 화면 위쪽이므로
            self.kill()