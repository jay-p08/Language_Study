import { DoubleLinkedList } from "./DoubleLinkedList.mjs";

class Deque {

    constructor() {
        this.list = new DoubleLinkedList();
    }

    printAll() {
        this.list.printAll();
    } // printAll()

    addFirst( data ) {
        this.list.insertAt( 0, data );
    } // addFirst()

    addLast( data ) {
        this.list.insertLast( data );
    } // addLast()

    removeFirst() {
        return this.list.deleteAt( 0 );
    } // removeFirst()

    removeLast() {
        return this.list.deleteAt( this.list.count - 1 );
    } // removeLast()

    isEmpty() {
        return this.list.isEmpty();
    } // isEmpty()

}

export { Deque };