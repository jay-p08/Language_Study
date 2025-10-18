function solution(str) {
    let answer = false;
    let stack = [];
    for ( let x of str ) {
        if( x === "(" ) {
            stack.push( x );
        } // if
        else  {
            if( stack.length == 0 ) {
                return false
            } // if
            stack.pop() 
        } // else
        console.log( stack );
    } // for

    if( stack.length == 0 ) {
        return true
    } // if

    return answer;
} // solution

let str = "(()()()())";
console.log( solution(str) );