/*
* Asset from: https://kenney.nl/assets/pixel-platformer
*
*/
import ASSETS from '../assets.js';
import ANIMATION from '../animation.js';
import Player from '../gameObjects/Player.js';
import PlayerBullet from '../gameObjects/PlayerBullet.js';
import EnemyFlying from '../gameObjects/EnemyFlying.js';
import EnemyBullet from '../gameObjects/EnemyBullet.js';
import Explosion from '../gameObjects/Explosion.js';

export class Game extends Phaser.Scene {
    constructor() {
        super('Game');
    }

    create() {
        this.gameStarted = false;

        if (!this.user_id) {
            this.login().then(() => {
                this.startGameSetup();
            });
        } else {
            this.startGameSetup();
        }
    }

    init(data) {
        // Start 씬에서 전달된 user_id가 없으면 null
        this.user_id = data.user_id || null;
    }

    update() {
        if (!this.groundLayer) return; // ← 추가
        this.updateMap();

        if (!this.gameStarted) return;

        this.player.update();
        if (this.spawnEnemyCounter > 0) this.spawnEnemyCounter--;
        else this.addFlyingGroup();
    }

    async login() {
        return new Promise(resolve => {
            // Phaser 텍스트
            this.add.text(this.scale.width / 2, 120, '🎮 Game Login', {
                fontSize: '48px', color: '#0ff', fontFamily: 'Arial Black', stroke: '#000', strokeThickness: 4
            }).setOrigin(0.5);

            // 로그인 박스 배경 (Phaser rectangle)
            const boxWidth = 400;
            const boxHeight = 300;
            const box = this.add.rectangle(
                this.scale.width / 2, this.scale.height / 2,
                boxWidth, boxHeight,
                0x000000, 0.7
            ).setStrokeStyle(3, 0x0ff);

            // 랭킹 텍스트
            const rankingText = this.add.text(
                this.scale.width / 2, this.scale.height / 2 - 80,
                'Loading ranking...', { fontSize: '20px', color: '#ff0', align: 'center', fontFamily: 'Arial' }
            ).setOrigin(0.5);

            fetch('http://localhost:3000/ranking')
                .then(res => res.json())
                .then(data => {
                    if (!Array.isArray(data) || data.length === 0) {
                        rankingText.setText('No ranking data');
                        return;
                    }

                    let text = '--- Top 3 ---\n';
                    data.slice(0, 3).forEach((row, i) => {
                        text += `${i + 1}. ${row.username} - ${row.score}\n`;
                    });
                    rankingText.setText(text);
                })
                .catch(err => {
                    console.error(err);
                    rankingText.setText('Error loading ranking');
                });

            // HTML input + button 스타일 적용
            const input = document.createElement('input');
            input.type = 'text';
            input.placeholder = 'Enter username';
            input.classList.add('login-input'); // CSS로 스타일링
            document.body.appendChild(input);

            const btn = document.createElement('button');
            btn.innerText = 'Start';
            btn.classList.add('login-btn'); // CSS로 스타일링
            document.body.appendChild(btn);

            // CSS는 외부 스타일로 추가
            const style = document.createElement('style');
            style.textContent = `
            .login-input {
                position: absolute;
                top: 50%;
                left: 50%;
                transform: translate(-50%, -10%);
                width: 250px;
                padding: 12px;
                font-size: 20px;
                border-radius: 12px;
                border: none;
                outline: none;
            }
            .login-btn {
                position: absolute;
                top: 62%;
                left: 50%;
                transform: translate(-50%, -50%);
                padding: 12px 25px;
                font-size: 20px;
                border-radius: 12px;
                border: none;
                background: #0f0;
                color: #000;
                cursor: pointer;
                transition: all 0.2s;
            }
            .login-btn:hover {
                background: #0c0;
            }
        `;
            document.head.appendChild(style);

            btn.onclick = async () => {
                const username = input.value.trim();
                if (!username) return alert('Please enter username!');

                try {
                    const res = await fetch('http://localhost:3000/login', {
                        method: 'POST',
                        headers: { 'Content-Type': 'application/json' },
                        body: JSON.stringify({ username, password: '1234' })
                    });
                    const data = await res.json();

                    if (data.error) {
                        const reg = await fetch('http://localhost:3000/register', {
                            method: 'POST',
                            headers: { 'Content-Type': 'application/json' },
                            body: JSON.stringify({ username, password: '1234' })
                        });
                        const regData = await reg.json();
                        this.user_id = regData.id;
                    } else this.user_id = data.id;

                    input.remove();
                    btn.remove();
                    resolve();
                } catch (err) {
                    console.error(err);
                    alert('Server error');
                }
            };
        });
    }

    startGameSetup() {
        this.initVariables();
        this.initGameUi();
        this.initAnimations();
        this.initPlayer();
        this.initInput();
        this.initPhysics();
        this.initMap();

        this.loadRanking();
        this.startGame();
    }

    async loadRanking() {
        try {
            const res = await fetch('http://localhost:3000/ranking');
            const ranking = await res.json();

            let rankingText = '🏆 Top 3 Ranking:\n';
            ranking.slice(0, 3).forEach((r, i) => { // 상위 3명만
                rankingText += `${i + 1}. ${r.username} - ${r.score}\n`;
            });

            // ✅ 게임 화면 상단 오른쪽에 표시
            this.rankingDisplay = this.add.text(this.scale.width - 300, 20, rankingText, {
                fontSize: '20px',
                color: '#0f0',
                align: 'right'
            }).setDepth(100);
        } catch (err) {
            console.error('랭킹 불러오기 실패:', err);
            this.add.text(this.scale.width - 250, 20, '(랭킹 불러오기 실패)', {
                fontSize: '20px',
                color: '#f00'
            }).setDepth(100);
        }
    }

    initVariables() {
        this.score = 0;
        this.centreX = this.scale.width * 0.5;
        this.centreY = this.scale.height * 0.5;

        // list of tile ids in tiles.png
        // items nearer to the beginning of the array have a higher chance of being randomly chosen when using weighted()
        this.tiles = [50, 50, 50, 50, 50, 50, 50, 50, 50, 110, 110, 110, 110, 110, 50, 50, 50, 50, 50, 50, 50, 50, 50, 110, 110, 110, 110, 110, 36, 48, 60, 72, 84];
        this.tileSize = 32; // width and height of a tile in pixels

        this.mapOffset = 10; // offset (in tiles) to move the map above the top of the screen
        this.mapTop = -this.mapOffset * this.tileSize; // offset (in pixels) to move the map above the top of the screen
        this.mapHeight = Math.ceil(this.scale.height / this.tileSize) + this.mapOffset + 1; // height of the tile map (in tiles)
        this.mapWidth = Math.ceil(this.scale.width / this.tileSize); // width of the tile map (in tiles)
        this.scrollSpeed = 1; // background scrolling speed (in pixels)
        this.scrollMovement = 0; // current scroll amount
        this.spawnEnemyCounter = 0; // timer before spawning next group of enemies

        this.map; // rference to tile map
        this.groundLayer; // reference to ground layer of tile map
    }

    initGameUi() {
        // Create tutorial text
        this.tutorialText = this.add.text(this.centreX, this.centreY, 'Tap to shoot!', {
            fontFamily: 'Arial Black', fontSize: 42, color: '#ffffff',
            stroke: '#000000', strokeThickness: 8,
            align: 'center'
        })
            .setOrigin(0.5)
            .setDepth(100);

        // Create score text
        this.scoreText = this.add.text(20, 20, 'Score: 0', {
            fontFamily: 'Arial Black', fontSize: 28, color: '#ffffff',
            stroke: '#000000', strokeThickness: 8,
        })
            .setDepth(100);

        // Create game over text
        this.gameOverText = this.add.text(this.scale.width * 0.5, this.scale.height * 0.5, 'Game Over', {
            fontFamily: 'Arial Black', fontSize: 64, color: '#ffffff',
            stroke: '#000000', strokeThickness: 8,
            align: 'center'
        })
            .setOrigin(0.5)
            .setDepth(100)
            .setVisible(false);
    }

    initAnimations() {
        if (this.anims.exists(ANIMATION.explosion.key)) return; // ← 중복 방지
        this.anims.create({
            key: ANIMATION.explosion.key,
            frames: this.anims.generateFrameNumbers(ANIMATION.explosion.texture, ANIMATION.explosion.config),
            frameRate: ANIMATION.explosion.frameRate,
            repeat: ANIMATION.explosion.repeat
        });
    }

    initPhysics() {
        this.enemyGroup = this.add.group();
        this.enemyBulletGroup = this.add.group();
        this.playerBulletGroup = this.add.group();

        this.physics.add.overlap(this.player, this.enemyBulletGroup, this.hitPlayer, null, this);
        this.physics.add.overlap(this.playerBulletGroup, this.enemyGroup, this.hitEnemy, null, this);
        this.physics.add.overlap(this.player, this.enemyGroup, this.hitPlayer, null, this);
    }

    initPlayer() {
        this.player = new Player(this, this.centreX, this.scale.height - 100, 8);
    }

    initInput() {
        this.cursors = this.input.keyboard.createCursorKeys();

        // check for spacebar press only once
        this.cursors.space.once('down', (key, event) => {
            this.startGame();
        });
    }

    // create tile map data
    initMap() {
        const mapData = [];

        for (let y = 0; y < this.mapHeight; y++) {
            const row = [];

            for (let x = 0; x < this.mapWidth; x++) {
                // randomly choose a tile id from this.tiles
                // weightedPick favours items earlier in the array
                const tileIndex = Phaser.Math.RND.weightedPick(this.tiles);

                row.push(tileIndex);
            }

            mapData.push(row);
        }
        this.map = this.make.tilemap({ data: mapData, tileWidth: this.tileSize, tileHeight: this.tileSize });
        const tileset = this.map.addTilesetImage(ASSETS.spritesheet.tiles.key);
        this.groundLayer = this.map.createLayer(0, tileset, 0, this.mapTop);
    }

    // scroll the tile map
    updateMap() {
        if (!this.map || !this.groundLayer) return;
        this.scrollMovement += this.scrollSpeed;

        if (this.scrollMovement >= this.tileSize) {
            //  Create new row on top
            let tile;
            let prev;

            // loop through map from bottom to top row
            for (let y = this.mapHeight - 2; y > 0; y--) {
                // loop through map from left to right column
                for (let x = 0; x < this.mapWidth; x++) {
                    tile = this.map.getTileAt(x, y - 1);
                    prev = this.map.getTileAt(x, y);

                    prev.index = tile.index;

                    if (y === 1) { // if top row
                        // randomly choose a tile id from this.tiles
                        // weightedPick favours items earlier in the array
                        tile.index = Phaser.Math.RND.weightedPick(this.tiles);
                    }
                }
            }

            this.scrollMovement -= this.tileSize; // reset to 0
        }

        this.groundLayer.y = this.mapTop + this.scrollMovement; // move one tile up
    }

    startGame() {
        this.gameStarted = true;
        this.tutorialText?.setVisible(false);
        this.addFlyingGroup();
    }

    fireBullet(x, y) {
        this.sound.play('shoot', { volume: 0.5 });

        const bullet = new PlayerBullet(this, x, y);
        this.playerBulletGroup.add(bullet);
    }

    removeBullet(bullet) {
        this.playerBulletGroup.remove(bullet, true, true);
    }

    fireEnemyBullet(x, y, power) {
        const bullet = new EnemyBullet(this, x, y, power);
        this.enemyBulletGroup.add(bullet);
    }

    removeEnemyBullet(bullet) {
        this.playerBulletGroup.remove(bullet, true, true);
    }

    // add a group of flying enemies
    addFlyingGroup() {
        this.spawnEnemyCounter = Phaser.Math.RND.between(5, 8) * 60; // spawn next group after x seconds
        const randomId = Phaser.Math.RND.between(0, 11); // id to choose image in tiles.png
        const randomCount = Phaser.Math.RND.between(5, 15); // number of enemies to spawn
        const randomInterval = Phaser.Math.RND.between(8, 12) * 100; // delay between spawning of each enemy
        const randomPath = Phaser.Math.RND.between(0, 3); // choose a path, a group follows the same path
        const randomPower = Phaser.Math.RND.between(1, 4); // strength of the enemy to determine damage to inflict and selecting bullet image
        const randomSpeed = Phaser.Math.RND.realInRange(0.0001, 0.001); // increment of pathSpeed in enemy

        this.timedEvent = this.time.addEvent(
            {
                delay: randomInterval,
                callback: this.addEnemy,
                args: [randomId, randomPath, randomSpeed, randomPower], // parameters passed to addEnemy()
                callbackScope: this,
                repeat: randomCount
            }
        );
    }

    addEnemy(shipId, pathId, speed, power) {
        const enemy = new EnemyFlying(this, shipId, pathId, speed, power);
        this.enemyGroup.add(enemy);
    }

    removeEnemy(enemy) {
        this.enemyGroup.remove(enemy, true, true);

        this.sound.play('boom', { volume: 0.5 });
    }

    addExplosion(x, y) {
        new Explosion(this, x, y);
    }

    hitPlayer(player, obstacle) {
        this.addExplosion(player.x, player.y);
        player.hit(obstacle.getPower());
        obstacle.die();

        this.GameOver();
    }

    hitEnemy(bullet, enemy) {
        this.updateScore(10);
        bullet.remove();
        enemy.hit(bullet.getPower());
    }

    updateScore(points) {
        this.score += points;
        this.scoreText.setText(`Score: ${this.score}`);
    }

    submitScore() {
        fetch("http://localhost:3000/submit-score", {
            method: "POST",
            headers: { "Content-Type": "application/json" },
            body: JSON.stringify({ user_id: user.id, score })
        });
    }

    GameOver() {
        this.gameStarted = false;
        this.gameOverText.setVisible(true);

        // 점수 서버 전송
        if (this.user_id) {
            fetch('http://localhost:3000/submit-score', {
                method: 'POST',
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify({ user_id: this.user_id, score: this.score })
            }).then(res => res.json()).then(console.log).catch(console.error);
        }
    }
}
