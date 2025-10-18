input = prompt( "숫자 입력" )
NumArr = [];

for( var i = 1 ; 7*i <= parseInt( input ) ; i++ ) {
    NumArr[i] = 7*i
}

alert( NumArr )