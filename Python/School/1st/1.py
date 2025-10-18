import keyword as K # 파이썬 키워드
import calendar as C # 달력
import datetime as D # 시간
import tkinter as TK # GUI 열기
import turtle as T # 그리기

T.shape( "turtle" )
T.speed( 10 )

def Turtle( ch, num ) :
    if( ch == "F" ) : T.forward( num )
    elif( ch == "L" ) : T.left( num )
    elif( ch == "R" ) : T.right( num )

Snum = [ 50, 72, 50, 144 ]
Pnum = [ 31, 72 ]
BPnum = [ 82, 72 ]
BSnum = [ 132.5, 72, 132.5, 144 ]
VBPnum = [ 215, 72 ]
VBSnum = [ 325, 71, 345, 144 ]
Smenu = [ "F", "L", "F", "R" ]
Pmenu = [ "F", "R" ]

T.color( 0, 1, 1)
for i in range( 5 ) :
    for j in range( 4 ) :
        Turtle( Smenu[ j ], Snum[ j ] )
Turtle( "F", 50 )

for i in range( 5 ) :
    for j in range( 2 ) :
        Turtle( Pmenu[ j ], Pnum[ j ] )
Turtle( "F", 82 )
Turtle( "R", 108 )

T.color( 1, 0, 1 )
for i in range( 5 ) :
    for j in range( 2 ) :
        Turtle( Pmenu[ j ], BPnum[ j ] )

T. color( 0.7, 0.5, 0.4 )
Turtle( "F", 215 )
Turtle( "R", 144 )

for i in range( 4 ) :
    for j in range( 4 ) :
        Turtle( Smenu[ j ], BSnum[ j ] )

for i in range( 3 ) :
    Turtle( Smenu[ i ], BSnum[ i ] )

Turtle( "R", 108 )
T.color( 0.5, 0, 0.5 )
for i in range( 5 ) :
    for j in range( 2 ) :
        Turtle( Pmenu[ j ], VBPnum[ j ] )

T.exitonclick()