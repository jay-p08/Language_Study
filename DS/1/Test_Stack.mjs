import { Stack } from "./Stack.mjs"

// let stack = []

// stack.push( 1 );
// stack.push( 2 );
// stack.push( 3 );
// stack.push( 4 );
// console.log( stack );

// console.log( stack.pop() );
// console.log( stack );

// console.log( stack.pop() );
// console.log( stack.pop() );

// console.log( stack );

let stack = new Stack();

console.log( "=== 첫번째 출력 ===" );
stack.Push( 1 );
stack.Push( 2 );
stack.Push( 3 );
stack.Push( 4 );

console.log( stack.Pop() );
console.log( stack.Pop() );
console.log( stack.Pop() );
console.log( stack.Pop() );
console.log( stack.Pop() );

console.log( "=== 두번째 출력 ===" );
stack.Push( "일" );
stack.Push( "이" );
stack.Push( "삼" );
stack.Push( "사" );
console.log( stack.Peek() );

stack.Pop();
console.log( stack.Peek() );
console.log( `IsEmpty : ${ stack.IsEmpty() }` );

stack.Pop();
stack.Pop();
stack.Pop();

console.log( `IsEmpty : ${ stack.IsEmpty() }` );