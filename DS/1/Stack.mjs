import { LinkedList } from "./LinkedList.mjs"

class Stack {
    constructor() {
        this.list = new LinkedList();
    }

    Push(data) {
        this.list.insertAt(0, data);
    } // Push

    Pop() {
        try {
            this.list.deleteAt(0);
        } catch (e) {
            return null;
        }
    } // Pop

    Peek() {
        return this.list.getNodeAt(0);
    } // Peek

    IsEmpty() {
        return (this.list.count == 0);
    } // IsEmpty
}

export { Stack }