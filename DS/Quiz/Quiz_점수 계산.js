function solution( arr ) {
    var answer = 0, num = 0;
    for( let x of arr ) {
        if( x == 1 ) {
            num++;
            answer += num;
        } // if
        else  {
            num = 0;
        } // else
    } // for

    return answer;
} // solution

let arr = [ 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 ];

console.log( solution(arr) )