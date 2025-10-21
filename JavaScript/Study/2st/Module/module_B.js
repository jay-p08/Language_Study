const { message, numbers, user, Person:Person3 } = require("./module_A.js");

console.log(message);      // Hello CommonJS
console.log(numbers);      // [1, 2, 3, 4, 5]
console.log(user.name);    // Kim

const p = new Person3("Lee");
console.log(p.greet());    // Hi, I'm Lee