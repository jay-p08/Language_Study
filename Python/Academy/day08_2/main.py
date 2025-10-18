# main.py
# main 파일은 파이게임을 동작시키는 메인 프레임으로
# 다른 객체인 enemy나 player, bullet 등을
# 다른 파일에서 받아와서 실행시키는 중앙통제실 역할을 한다

# player는 사용자가 컨트롤 하는 객체로
# 하나만 만들 것이다.

# enemy는 화면 상단에서 무작위로 생성되어
# player를 항해 아래로 내려올 것이다
# + player와 닿으면( 충돌 ) 게임 오버

# bullet은 player가 스페이스바를 누르면 발사 되는 무기로
# enemy와 충돌하면 enemy 객체가 사라지게 만든다

import pygame
import time
from player import Player
from enemy import Enemy
from bullets import Bullet

# 파이게임 게임판 초기화
pygame.init()

# 게임 화면 크기 설정
WIDTH, HEIGHT = 800, 600

# 설정대로 스키린 설정
screen = pygame.display.set_mode( ( WIDTH, HEIGHT ) )
# 게임창 제목 설정
pygame.display.set_caption( "Space Shooter" )

# 스프라이트
# 게임 화면 위에 나타내기 위해 만들어내는 객체의 일종으로
# 화면 위에 올리거나 내리거나 하는 등의 목적으로
# 만들어낸다.
# 이때 스프라이트를 그룹으로 묶어서 일괄 관리를 하기도 한다
# 스프라이트 그룹 생성
all_sprites = pygame.sprite.Group()
# 적을 담을 스프라이트 그룹 생성
enemies = pygame.sprite.Group()
# 총알을 그릴 스프라이트 그룹 생성
bullets = pygame.sprite.Group()

# 플레이어 스프라이트 생성
player = Player()
all_sprites.add( player )

# 색상을 상수로 정의
BLACK = ( 0, 0, 0 )
WHITE = ( 255, 255, 255 )
# 초기 적 생성
for i in range( 8 ) : # 적 8마리 생성
    enemy = Enemy()
    #
    all_sprites.add( enemy )
    #
    enemies.add( enemy )

# 게임 오버 상태 변수
game_over = False

# 폰트 설정
font = pygame.font.Font( None, 74 )

# 본격적인 게임 루프 시작
# pygame은 모든 동작이 반복문 안에서 실행되며
# 화면을 그리고 지우는 모든 동작이 반복문 안에서 아주 빠른 동작 아래
# 실행된다
# 루프 안에서 이벤트 발생 시 이를 감지하고
# 감지한 이벤트에 대한 동작을 정의하는 것으로
# 해당 동작이 조건에 따라 실행된다
# 게임 실행 중 여부를 담을 변수
running = True

while running : 
    # 이벤트 처리
    for event in pygame.event.get() :
        # 만약 pygame의 종료 이벤트가 감지되면
        if event.type == pygame.QUIT :
            # 실행상태를 False로 변경
            running = False # 이를 통해 게임 루프 탈출( 종료 )
        # 스페이스바를 누르면 총알 생성
        if event.type == pygame.K_SPACE :
            # 플레이어의 중심을 x좌표로
            # 플레이어 객체의 상단을 y좌표로 하여
            # 총알 생성
            bullet = Bullet( player.rect.centerx, player.rect.top )
            all_sprites.add( bullet )
            bullets.add( bullet )

        if not game_over : # 게임 오버가 아니면
            # 모든 스프라이트 업데이트
            all_sprites.update()

            # 총악 - 적 충돌 로직
            # 적과 총알 충돌 감지
            hits = pygame.sprite.groupcollide( enemies, bullet, True, True )
            for hit in hits :
                enemy = Enemy
                all_sprites.add( enemy )
                enemies.add( enemy )

            # 게임 오버 로직
            # 적과 플레이어 충돌 감지
            if pygame.sprite.spritecollideany( player, enemies ) :
                # 적 그룳의 적 중 하나라도 플레이어와 닿으면
                game_over = True # 게임 오버

        # 화면을 검은색으로 채우기
        screen.fill( BLACK )

        # 화면을 그리기
        all_sprites.draw( screen )

        # 게임오버에 관한 메시지 표시
        if game_over : 
            game_over_text = font.render( "Game Over", True, WHITE )
            text_rect = game_over_text.get_rect( center = ( WIDTH // 2 , HEIGHT // 2 ) )
            screen.blit( game_over_text, text_rect )

        pygame.display.flip()
        # 지연시간 30ms
        pygame.time.delay( 30 )

time.sleep( 3 ) # 초 동안 텍스트 표시
# pygame 창 닫기
pygame.quit()