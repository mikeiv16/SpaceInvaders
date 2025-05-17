#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "GameObject.h"
#include "Bullet.h"
#include "Enemy.h"
#include <vector>

class Game {
public:
	static Game& get();
	void addBullet(Bullet* bullet) { bullets.push_back(bullet); }
	void addEnemy(Enemy* enemy) { enemies.push_back(enemy); }
	void initializeEnemies();
	void input();
	void update();
	void checkCollisions();
	void render();
	void run();
private:
	Game() = default;           
	~Game();
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	Player player;
	std::vector<GameObject*> enemies;
	std::vector<GameObject*> bullets;
	int score;
	int level;
	bool running;
};

#endif