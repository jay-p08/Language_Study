export const message = "Hello ES Module (mjs)";

// 배열
export const numbers = [10, 20, 30];

// 객체
export const user = { name: "Park", age: 25 };

// 클래스
export class Person {
  constructor(name) {
    this.name = name;
  }
  greet() {
    return `Hello, I'm ${this.name}`;
  }
}