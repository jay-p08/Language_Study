function sayHello() {
    console.log("Hello!");
}

function limitFunc(func, limit) {
    let count = 0;
    return function () {
        if (count < limit) {
            func();
            count++;
        }
        else {
            console.log("더 이상 실행할 수 없습니다.");
        }
    }
}

const limitedHello = limitFunc(sayHello, 2);

limitedHello(); // "Hello!"
limitedHello(); // "Hello!"
limitedHello(); // "더 이상 실행할 수 없습니다"