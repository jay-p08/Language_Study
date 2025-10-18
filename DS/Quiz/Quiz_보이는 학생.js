function solution( arr ) {
    var answer = 0, max = 0;
    for( let i = 0 ; i < arr.length ; i++ ) {
        if( arr[i] > max ) {
            max = arr[i];
            answer++;
        }
    }

    return answer;
} // solution

let arr = [ 130, 135, 148, 140, 145, 150, 150, 153 ];

console.log( solution(arr) )