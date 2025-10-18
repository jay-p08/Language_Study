const students7 = [
  { name: "Kim", score: 80 },
  { name: "Lee", score: 95 },
  { name: "Park", score: 70 }
];

const hasPerfect = students7.some( s => s.score == 100 );
console.log(hasPerfect); // false

students7.push({ name: "Jeon", score: 100 })
const hasPerfect2 = students7.some( s => s.score == 100 );
console.log(hasPerfect2); // true