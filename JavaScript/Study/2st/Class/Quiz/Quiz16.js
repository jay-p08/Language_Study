const subject = [ "javascript", "java", "python", "c++", "typescript" ];
const subjectJava = subject.filter( /java/i.test.bind( /java/i ) );

console.log(subjectJava); // ["javascript", "java"]