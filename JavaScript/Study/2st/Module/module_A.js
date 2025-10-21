const message = "Hello CommonJS";

// 배열
const numbers = [1, 2, 3, 4, 5];

// 객체
const user = { name: "Kim", age: 20 };

// 클래스
class Person {
  constructor(name) {
    this.name = name;
  }
  greet() {
    return `Hi, I'm ${this.name}`;
  }
}

// 한 번에 내보내기
module.exports = {
  message,
  numbers,
  user,
  Person,
};