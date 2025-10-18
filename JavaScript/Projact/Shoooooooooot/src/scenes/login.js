// login.js
export async function showLogin() {
    const rankingEl = document.getElementById('ranking');
    const usernameInput = document.getElementById('username');
    const btn = document.getElementById('login-btn');

    // 랭킹 불러오기
    try {
        const res = await fetch('http://localhost:3000/ranking');
        const data = await res.json();

        if (!Array.isArray(data) || data.length === 0) {
            rankingEl.textContent = 'No ranking data';
        } else {
            let text = '--- Top 3 Ranking ---\n';
            data.slice(0, 3).forEach((row, i) => {
                text += `${i + 1}. ${row.username} - ${row.score}\n`;
            });
            rankingEl.textContent = text;
        }
    } catch (err) {
        console.error(err);
        rankingEl.textContent = 'Error loading ranking';
    }

    return new Promise(resolve => {
        btn.onclick = async () => {
            const username = usernameInput.value.trim();
            if (!username) return alert('Please enter a username!');

            try {
                const res = await fetch('http://localhost:3000/login', {
                    method: 'POST',
                    headers: { 'Content-Type': 'application/json' },
                    body: JSON.stringify({ username, password: '1234' })
                });
                const data = await res.json();

                let userId;
                if (data.error) {
                    const reg = await fetch('http://localhost:3000/register', {
                        method: 'POST',
                        headers: { 'Content-Type': 'application/json' },
                        body: JSON.stringify({ username, password: '1234' })
                    });
                    const regData = await reg.json();
                    userId = regData.id;
                } else {
                    userId = data.id;
                }

                // 로그인 완료 후 UI 숨기기
                document.getElementById('login-container').style.display = 'none';
                resolve(userId);
            } catch (err) {
                console.error(err);
                alert('Server error');
            }
        };
    });
}
