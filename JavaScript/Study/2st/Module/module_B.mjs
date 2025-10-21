import { message, numbers, user, Person } from "./module_A.mjs";

console.log(message);      // Hello ES Module (mjs)
console.log(numbers);      // [10, 20, 30]
console.log(user.age);     // 25

const p = new Person("Choi");
console.log(p.greet());    // Hello, I'm Choi