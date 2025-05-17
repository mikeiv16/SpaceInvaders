#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "GameObject.h"
#include <vector>

class Game {
public:
	void initializeEnemies();
	void input();
	void update();
	void checkCollisions();
	void render();
	void run();
private:
	Player player;
	std::vector<GameObject*> enemies;
	std::vector<GameObject*> bullets;
	int score;
	int level;
	bool running;
};

#endif