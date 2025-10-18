input = prompt( "어떤 음료를 주문하시겠습니까?( 1 : 커피, 2 : 에이드, 3 : 스무디 )" )

var coffee = 100
var ade = 200
var smoothie = 300

switch ( input ) {
    case "1":
        alert( "커피 나왔습니다 가격은 " + coffee + "원 입니다." )
        break;
    case "2" :
        alert( "에이드 나왔습니다 가격은 " + ade + "원 입니다." )
        break
    case "3" :
        alert( "스무디 나왔습니다 가격은 " + smoothie + "원 입니다.")
        break
    default : 
        alert( "제대로 골라주세요." )
        break;
}