input1 = prompt( "숫자 입력" )
input2 = prompt( "두번째 숫자 입력" )

var isInput1 = input1 >= 10 && input1 < 40;
var isInput2 = input2 >= 10 && input2 < 40;

if( isInput1 && isInput2 ) alert( "맞습니다" )
else if( isInput1 || isInput2 ) alert( "하나만 조건에 맞습니다" )
else alert( "아닙니다" )