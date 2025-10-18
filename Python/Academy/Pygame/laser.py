import pygame
# 파이게임에서 쓸 레이저 클래스 정의
class Laser( pygame.sprite.Sprite ) :
    def __init__( self, x, y ) :
        super().__init__()
        # 레이저 이미지와 위치 초기화
        self.image = pygame.Surface( ( 5, 15 ) )
        self.image.fill( ( 255, 255, 0 ) ) # 노란색 레이저

        self.rect = self.image.get_rect()
        self.rect.centerx = x
        self.rect.bottom = y

    # 스프라이트 업데이트를 할 때 실행할 코드
    def update( self ) :
        # 레이저를 위로 이동
        self.rect.y -= 10
        # 화면 밖으로 나가면 제거
        if self.rect.bottom < 0 :
            self.kill # 해당 객체 스프라이트 삭제