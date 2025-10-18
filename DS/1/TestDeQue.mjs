import { Deque } from "./Deque.mjs";

let deque = new Deque();

console.log( `isEmpty >>> ${ deque.isEmpty() }` );
console.log( "========= Add First ==========" );

deque.addFirst( 1 );
deque.addFirst( 2 );
deque.addFirst( 3 );
deque.addFirst( 4 );
deque.addFirst( 5 );

// console.log( deque );
deque.printAll();

console.log( `isEmpty >>> ${ deque.isEmpty() }\n` );
console.log( "========= Remove First ==========" );

deque.removeFirst();
deque.printAll();
deque.removeFirst();
deque.printAll();
deque.removeFirst();
deque.printAll();
deque.removeFirst();
deque.printAll();
deque.removeFirst();
deque.printAll();

console.log( `isEmpty >>> ${ deque.isEmpty() }\n` );
console.log( "========= Add Last ==========" );

deque.addLast( 1 );
deque.addLast( 2 );
deque.addLast( 3 );
deque.addLast( 4 );
deque.addLast( 5 );

deque.printAll();

console.log( `isEmpty >>> ${ deque.isEmpty() }\n` );
console.log( "========= Remove Last ==========" );

deque.removeLast();
deque.printAll();
deque.removeLast();
deque.printAll();
deque.removeLast();
deque.printAll();
deque.removeLast();
deque.printAll();
deque.removeLast();
deque.printAll();

console.log( `isEmpty >>> ${ deque.isEmpty() }\n` );