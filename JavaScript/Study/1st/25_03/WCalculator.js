const calculator = ( num1, num2, op ) => {
    switch ( op ) {
        case '+':
            return num1 + num2;
        case '-' :
            return num1 - num2;
        case '*' :
            return num1 * num2;
        case '/' :
            if ( num1 == 0 || num2 == 0 ) {
                return "0으로 나눌 수 없습니다."
            } else return num1 / num2;
        default :
            break;
    }
}

alert( calculator( 10, 5, '+' ) );
alert( calculator( 7, 2, '-' ) );
alert( calculator( 4, 3, '*' ) );
alert( calculator( 8, 2, '/' ) );
alert( calculator( 5, 0, '/' ) );
