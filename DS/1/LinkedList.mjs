// Node
class Node {
    constructor( data, next ) {
        this.data = data; this.next = next;
    }
}

// LinkedList
class LinkedList {

    constructor() {
        this.head = null;
        this.count = 0;
    }

    // insertAt
    insertAt( index, data ) {

        if( index > this.count || index < 0 )
            throw new Error( "index ë²”ìœ„ë¥? ë²—ì–´?‚¨." );

        let newNode = new Node( data );

        if( index == 0 ) {
            newNode.next = this.head;
            this.head = newNode; 
        } else {
            let currentNode = this.head;
            
            for( let i = 0 ; i < index - 1 ; i++ ) {
                currentNode = currentNode.next;
            }

            newNode.next = currentNode.next
            currentNode.next = newNode;
        }

        this.count++;
    } // insertAt

    // insertLast
    insertLast( data ) {
        this.insertAt( this.count, data )
    } // insertLast

    // deleteAt
    deleteAt( index ) {
        if( index > this.count || index < 0 )
            throw new Error( "index error." );

        let currentNode = this.head;

        if( index == 0 ) {
            let deleteNode = this.head;
            this.head = this.head.next;
            this.count--;

            return deleteNode;
        } // if
        else {
            for( let i = 0 ; i < index-1 ; i++ ) {
                currentNode = currentNode.next;
            } // for

            let deleteNode = currentNode.next;
            currentNode.next = currentNode.next.next;
            this.count--;

            return deleteNode;
        } // else
        
    } // deleteAt

    // deleteLast
    deleteLast() {
        return this.deleteAt( this.count - 1 )
    } // deleteLast

    // getNodeAt
    getNodeAt( index ) {
        if( index > this.count || index < 0 )
            throw new Error( "index error." );

        let currentNode = this.head;

        for( let i = 0 ; i < index ; i++ ) {
            currentNode = currentNode.next;
        }

        return currentNode.data;
    } // getNodeAt

    // printAll
    printAll() {
        let currentNode = this.head;
        let text = "[ ";

        // while
        while( currentNode != null ) {
            text += currentNode.data;
            currentNode = currentNode.next;
            if( currentNode != null ) {
                text += ", ";
            }
        } // while
        
        text += " ]"
        console.log( text )
    } // printAll

    // clear
    clear() {
        this.head = null;
        this.count = 0;
    } // clear
} // LinkedList

export {Node, LinkedList};