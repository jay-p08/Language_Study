const students7 = [
  { name: "Kim", score: 80 },
  { name: "Lee", score: 95 },
  { name: "Park", score: 70 }
];

const hasFail = students7.some( s => s.score < 60 );
console.log(hasFail); // false
  
students7.push({ name: "Han", score: 20 });
const hasFail2 = students7.some( s => s.score < 60 );
console.log(hasFail2); // true