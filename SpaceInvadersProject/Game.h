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
	void addBullet(Bullet*);
	void addEnemy(Enemy*);
	void initializeEnemies();
	void input();
	void update();
	void checkCollisions();
	void render();
	void run();
	void checkLevel();
	void initializeStatusBar(int, int, int);
private:
	Player player;
	std::vector<GameObject*> enemies;
	std::vector<GameObject*> bullets;
	int score;
	int level;
	bool isRunning;
	bool gotExtraLife;
};

#endif