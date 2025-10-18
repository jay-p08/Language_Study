import { DoubleLinkedList } from "./DoubleLinkedList.mjs";

class Queue {
    constructor() {
        this.list = new DoubleLinkedList();
    } // constructor()

    enqueue( data ) {
        this.list.insertAt( 0, data );
    } // enqueue()

    dequeue() {
        try {
            return this.list.deleteLast();
        } // try
        catch( e ) {
            return null;
        } // catch
    } // dequeue()

    front() {
        return this.list.tail;
    } // front()

    isEmpty() {
        return (this.list.count == 0);
    } // isEmpty
} // class Queue

export { Queue }