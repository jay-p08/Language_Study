class Person {
    constructor( name ) {
        this.name = name;
    }

    greet() {
        return `"Hi, I'm [${ this.name }]"`;
    }
}

class Student extends Person {
    constructor( name, id ) {
        super( name );
        this.id = id;
    }
    study() {
        console.log( `"[${ this.name }] 는 공부중입니다."` );
    }
    greet() {
        super.greet();
        console.log( `"학생 [${ this.name }]"` );
    }
}

// 출력 및 확인
const s1 = new Student("김윤지", "2025");
s1.greet();
s1.study(); 