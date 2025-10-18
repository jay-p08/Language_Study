class Exam {
    constructor( score = 0 ) {
        this.score = score;
    }
}

const exam1 = new Exam();

console.log(exam1.score); // 불합격
exam1.score = 85; 
console.log(exam1.score); // 합격 : 85

const exam2 = new Exam(90);
console.log(exam1.score);  // 합격 : 90
exam1.score = 40; 
exam1.score = 150; 
console.log(exam1.score); // 불합격