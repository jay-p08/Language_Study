import express from "express";
import sqlite3 from "sqlite3";
import bcrypt from "bcrypt";
import bodyParser from "body-parser";
import cors from "cors";

const app = express();
app.use(cors());
app.use(bodyParser.json());

const db = new sqlite3.Database("./shmup.sql");

// 테이블 생성
db.run(`CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT UNIQUE,
    password TEXT
)`);

db.run(`CREATE TABLE IF NOT EXISTS scores (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id INTEGER,
    score INTEGER,
    FOREIGN KEY(user_id) REFERENCES users(id)
)`);

// 회원가입
app.post("/register", async (req, res) => {
    const { username, password } = req.body;
    const hash = await bcrypt.hash(password, 10);
    db.run("INSERT INTO users (username, password) VALUES (?, ?)", [username, hash], function(err){
        if(err) return res.status(400).json({error: err.message});
        res.json({id: this.lastID, username});
    });
});

// 로그인
app.post("/login", (req, res) => {
    const { username, password } = req.body;
    db.get("SELECT * FROM users WHERE username=?", [username], async (err, row) => {
        if(!row) return res.status(400).json({error: "User not found"});
        const match = await bcrypt.compare(password, row.password);
        if(match) res.json({id: row.id, username: row.username});
        else res.status(400).json({error: "Wrong password"});
    });
});

// 점수 제출
app.post("/submit-score", (req, res) => {
    const { user_id, score } = req.body;
    db.run("INSERT INTO scores (user_id, score) VALUES (?, ?)", [user_id, score], function(err){
        if(err) return res.status(400).json({error: err.message});
        res.json({success: true});
    });
});

// 랭킹 조회
app.get("/ranking", (req, res) => {
    db.all(`SELECT users.username, MAX(scores.score) as score
            FROM scores JOIN users ON scores.user_id = users.id
            GROUP BY users.id
            ORDER BY score DESC
            LIMIT 10`, [], (err, rows) => {
        if(err) return res.status(400).json({error: err.message});
        res.json(rows);
    });
});

app.listen(3000, () => console.log("✅ Server running on http://localhost:3000"));