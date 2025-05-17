#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"

class Enemy : public GameObject {
public:
	Enemy(int = 0, int = 0, char = ' ', COLORS = WHITE, int = 0);
	Enemy(const Enemy&);
	Enemy& operator=(const Enemy&);
	virtual ~Enemy();

	void update();
	void render();
private:
	int direction;
};

class EnemyType1 : public Enemy{

};

#endif