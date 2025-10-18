export class Start extends Phaser.Scene {
    constructor() {
        super('Start');
    }

    create() {
        this.add.text(640, 150, 'JShmup', { fontSize: '64px', color: '#fff' }).setOrigin(0.5);
        this.add.text(640, 220, 'Enter your username:', { fontSize: '28px', color: '#fff' }).setOrigin(0.5);

        // 입력 DOM 추가
        const input = document.createElement('input');
        input.type = 'text';
        input.placeholder = 'Username';
        input.style.position = 'absolute';
        input.style.top = '50%';
        input.style.left = '50%';
        input.style.transform = 'translate(-50%, -50%)';
        input.style.fontSize = '24px';
        input.style.padding = '5px';
        input.style.width = '200px';
        document.body.appendChild(input);

        // 버튼 DOM 추가
        const btn = document.createElement('button');
        btn.innerText = 'Start';
        btn.style.position = 'absolute';
        btn.style.top = '60%';
        btn.style.left = '50%';
        btn.style.transform = 'translate(-50%, -50%)';
        btn.style.fontSize = '24px';
        btn.style.padding = '5px 10px';
        document.body.appendChild(btn);

        btn.onclick = async () => {
            const username = input.value.trim();
            if (!username) return alert('Please enter a username!');

            let user_id;

            // 로그인 시도
            try {
                const res = await fetch('http://localhost:3000/login', {
                    method: 'POST',
                    headers: { 'Content-Type': 'application/json' },
                    body: JSON.stringify({ username, password: '1234' }) // 간단히 임시 비밀번호 사용
                });
                const data = await res.json();
                if (data.error) {
                    // 회원가입
                    const reg = await fetch('http://localhost:3000/register', {
                        method: 'POST',
                        headers: { 'Content-Type': 'application/json' },
                        body: JSON.stringify({ username, password: '1234' })
                    });
                    const regData = await reg.json();
                    user_id = regData.id;
                    alert(`New user created: ${username}`);
                } else {
                    user_id = data.id;
                }
            } catch (err) {
                console.error(err);
                alert('Server error');
                return;
            }

            // DOM 제거
            input.remove();
            btn.remove();

            // 게임 시작
            this.scene.start('Game', { user_id });
        };

    }
    async onLoginSuccess(user_id) {
        this.user_id = user_id;
        await this.loadRanking(); // ✅ 로그인 화면에서 먼저 표시
    }
}
