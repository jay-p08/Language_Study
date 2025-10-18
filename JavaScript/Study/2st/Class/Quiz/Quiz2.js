const person = {};
const person2 = { job:"teacher" };

person.job = person2.job; person2.job = "student";
delete person2.jop;