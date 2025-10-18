import { Boot } from './scenes/Boot.js';
import { Preloader } from './scenes/Preloader.js';
import { Start } from './scenes/Start.js';
import { Game } from './scenes/Game.js';

const config = {
    type: Phaser.AUTO,
    title: 'Shmup',
    parent: 'game-container',
    width: 1280,
    height: 720,
    backgroundColor: '#000000',
    physics: { default: 'arcade', arcade: { gravity: { y: 0 }, debug: false } },
    scene: [ Boot, Preloader, Start, Game ],
    scale: { mode: Phaser.Scale.FIT, autoCenter: Phaser.Scale.CENTER_BOTH }
};

new Phaser.Game(config);
