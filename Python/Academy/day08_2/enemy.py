# enemy.py
import pygame
import random # 생성되는 위치를 무작위로 하기 위해
# 랜덤 모듈 임포트

class Enemy(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        # 해당 객체를 그린다.
        self.image = pygame.Surface((50, 50))
        # 색 지정
        self.image.fill((255, 0, 0)) # 빨간색으로 변경

        # 스프라이트라면 반드시 설정해주어야 하는 것
        self.rect = self.image.get_rect()
        # 스프라이트가 화면상에 그려질 좌표를 무작위로 설정
        self.rect.x = random.randint(0, 800 - 50) # 0부터 750 사이의 값을 가진다.
        # 화면 상단 바깥쪽에서 생성되어 내려오도록 설정하기 위해
        # y좌표는 음수로 설정한다.
        self.rect.y = random.randint(-100, -40) # -100부터 -40 사이의 값을 가진다.
    
    # 스프라이트 업데이트 메서드
    def update(self):
        self.move()
    
    # 움직임 정의 메서드
    def move(self):
        self.rect.y += 5 # 화면 아래로 이동
        if self.rect.top > 600: # 화면 크기보다 더 아래로 내려가서
            # rect.top 객체의 윗부분이 화면 아래로 내려가면
            # 위치를 재설정
            # 아래 코드는 이전에 쓴 적이 있는 코드이므로
            # + 나중에 따로 모아서 관리
            self.rect.x = random.randint(0, 800-50)
            self.rect.y = random.randint(-100, -40)
        # + 이동속도를 랜덤하게 조정하는 것을 나중에