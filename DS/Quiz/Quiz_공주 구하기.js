import { Queue } from "../Queue.mjs";

function solution( num, K ) {
    let queue = Array.from( { length:num }, ( v, i ) => ( i + 1 ) );
    let answer = 0;
    
    
    while ( true ) {
        for( let i = 1 ; i < K ; i++ ) queue.push(queue.shift());
        queue.shift()
        if( queue.length == 1 ) { answer = queue.shift(); break; }
    }
    return answer
} // solution

let num = 8;
let K = 3;
console.log(solution( num, K ) );