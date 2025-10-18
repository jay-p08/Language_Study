class Node {
    constructor(data, next = null, prev = null) {
        this.data = data; this.next = next; this.prev = prev;
    } // constructor()
} // Class Node

class DoubleLinkedList {

    constructor() {
        this.head = null;
        this.tail = null;
        this.count = 0;
    } // constructor()

    insertAt(index, data) {

        if (index > this.count || index < 0) {
            throw new Error("index error.");
        } // if

        let newNode = new Node(data);

        if (index == 0) {
            newNode.next = this.head;
            if (this.head != null) {
                this.head.prev = newNode;
            } // if
            this.head = newNode;
        } // if
        else if (index === this.count) {
            newNode.next = null;
            newNode.prev = this.tail;
            this.tail.next = newNode;
        } // else if
        else {
            let currentNode = this.head;

            for (let i = 0; i < index - 1; i++) {
                currentNode = currentNode.next;
            } // for
            
            newNode.next = currentNode.next
            newNode.prev = currentNode;
            currentNode.next = newNode;
            newNode.next.prev = newNode;
        } // else

        if (newNode.next === null) {
            this.tail = newNode;
        } // if

        this.count++;
    } // insertAt()

    insertLast(data) {
        this.insertAt(this.count, data)
    } // insertLast()

    deleteAt(index) {
        if (index > this.count || index < 0) {
            throw new Error("index error.");
        } // if

        let currentNode = this.head;

        if (index == 0) {
            let deleteNode = this.head;

            if (this.head.next === null) {
                this.head = null; this.tail = null;
            } // if
            else {
                this.head = this.head.next;
                this.head.prev = null;
            } // else

            this.count--;

            return deleteNode;
        } // if
        else if (index === this.count - 1) {
            let deleteNode = this.tail;
            this.tail.prev.next = null;
            this.tail = this.tail.prev;
            this.count--;

            return deleteNode;
        } // else if
        else {
            for (let i = 0; i < index - 1; i++) {
                currentNode = currentNode.next;
            } // for

            let deleteNode = currentNode.next;
            currentNode.next = currentNode.next.next;
            currentNode.prev = currentNode;
            this.count--;

            return deleteNode;
        } // else

    } // deleteAt()

    deleteLast() {
        return this.deleteAt(this.count - 1)
    } // deleteLast()

    getNodeAt(index) {
        if (index > this.count || index < 0) {
            throw new Error("index error.");
        } // if

        let currentNode = this.head;

        for (let i = 0; i < index; i++) {
            currentNode = currentNode.next;
        } // for

        return currentNode.data;
    } // getNodeAt()

    printAll() {
        let currentNode = this.head;
        let text = "[ ";

        // while
        while (currentNode != null) {
            text += currentNode.data;
            currentNode = currentNode.next;
            if (currentNode != null) {
                text += ", ";
            }
        } // while

        text += " ]"
        console.log(text)
    } // printAll()

    clear() {
        this.head = null;
        this.count = 0;
    } // clear()

    isEmpty() {
        return this.count === 0;
    } // isEmpty()
} // Class DoubleLinkedList

export { Node, DoubleLinkedList };