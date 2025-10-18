class Person {
    constructor( name ) {
        this.name = name;
    }

    greet() {
        return `"Hi, I'm [${ this.name }]"`;
    }
}

//name을 받는 생성자 만들기

//greet() 메서드 만들기

const p1 = new Person("김윤지");
console.log(p1.greet()); // 메서드 출력