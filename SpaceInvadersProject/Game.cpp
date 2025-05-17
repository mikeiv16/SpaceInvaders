#include "Game.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include "GameObject.h"
#include <conio.h> // za input


Game& Game::get() {
    static Game instance;
    return instance;
}

void Game::initializeEnemies() {
    enemies.clear();
    int spacing = 6;
    for (int i = 0; i < 10; i++) {
        switch (level) {
            case 1: {
                enemies.push_back(new EnemyType1(10 + spacing * i, 3));
                break;
            }
            case 2: {
                enemies.push_back(new EnemyType2(10 + spacing * i, 3));
                break;
            }
            case 3: {
                enemies.push_back(new EnemyType3(10 + spacing * i, 3));
                break;
            }
        }  
    }
    if (level == 3) {
        for (int i = 0; i < 5; ++i) {
            enemies.push_back(new EnemyType4(15 + spacing * i, 5));
        }
    }
}

void Game::input() {
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
            case 'a': case 'A': player.moveLeft(); break;
            case 'd': case 'D': player.moveRight(); break;
            case ' ': player.shoot(); break;
        }
    }
}

void Game::update() {
}

void Game::checkCollisions() {

}

void Game::render() {
    for (int i = 0; i < POLE_ROWS; i++) cout << "=";
    cout << endl;
    cout << "Lives: " << player.getLives() << "   Level: " << this->level << "    Score: " << player.getScore() << endl;
    for (int i = 0; i < POLE_ROWS; i++) cout << "=";
    cout << endl;

}
void Game::run() {
    Player newPlayer(0, 0, '*', YELLOW, 3, 0);
    player = newPlayer;
    render();

    system("pause");
}

void Game::addBullet(Bullet* bullet) {
    bullets.push_back(bullet);
}

void Game::addEnemy(Enemy* enemy) { 
    enemies.push_back(enemy); 
}