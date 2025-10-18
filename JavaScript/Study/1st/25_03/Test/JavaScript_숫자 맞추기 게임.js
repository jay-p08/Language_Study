function startGame() {
    let isGameStart = confirm("숫자 맞추기 게임에 오신 것을 환영합니다!\n1부터 100 사이의 숫자를 맞춰보세요.");
    let isGameOver = true;
    let isGameReStart = false;

    do {
        if (isGameStart) {
            let randomNumber = Math.floor(Math.random() * 100 + 1);
            console.log(randomNumber);

            for (let i = 1; i <= 10; i++) {
                let inputNumber = prompt("숫자를 입력하세요");
                if (inputNumber == randomNumber) {
                    alert(`축하합니다. ${i}번 만에 숫자를 맞추셨습니다.\n정답은 ${randomNumber}였습니다.`);
                    isGameOver = false;
                    break;
                } // if
                else if (inputNumber == 0) {
                    alert('1부터 100사이의 숫자를 입력해주세요');
                    i--;
                } // else if
                else if (inputNumber > randomNumber) {
                    alert("DOWN! 더 작은 숫자를 입력해보세요!");
                } // else if
                else if (inputNumber < randomNumber) {
                    alert("UP! 더 큰 숫자를 입력해보세요!");
                } // else if
                else {
                    alert('1부터 100사이의 숫자를 입력해주세요');
                    i--;
                }
            } // for

            if (isGameOver) {
                alert(`게임 오버!\n정답은 ${randomNumber}였습니다!`)
            } // if

            isGameReStart = confirm( "다시 도전하겠습니까?" );
        } // if
    } while( isGameReStart );
    // do while
} // startGame