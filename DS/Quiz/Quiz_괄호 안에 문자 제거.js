function solution( str ) {
    let stack = [];
    let answer = "";

    for ( let x of str ) {
        if( x != ")" ) {
            stack.push( x )
        } // if
        else {
            while ( true ) {
                stack.pop()
                if( stack.lastIndexOf( "(" ) < 0 ) break;
            } // while
        } // else
        
    } // for
    return stack.join( " " );
} // solution

let str = "(A(BC)D)EF(G(H)(IJ)K)LM(N)";
console.log( solution( str ) );