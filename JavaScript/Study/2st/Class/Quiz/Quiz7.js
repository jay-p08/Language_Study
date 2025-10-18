const fruits = ['apple', 'banana', 'cherry', 'grape']; 
const [ first, second, ...others ] = fruits;

console.log(first) // apple
console.log(second) // banana
console.log(others) // ['cherry','grape']