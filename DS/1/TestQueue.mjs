import { Queue } from "./Queue.mjs";

let queue = new Queue();
console.log( "===== enqueue() 네 번 호출 =====" );

queue.enqueue( 1 );
queue.enqueue( 2 );
queue.enqueue( 3 );
queue.enqueue( 4 );

console.log( queue )

console.log( `isEmpty : ${ queue.isEmpty() }` );