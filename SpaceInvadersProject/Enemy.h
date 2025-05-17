#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"

class Enemy : public GameObject {
public:
	Enemy(int = 0, int = 0, char = ' ', COLORS = BLACK, int = 0);
	Enemy(const Enemy&);
	Enemy& operator=(const Enemy&);
	virtual ~Enemy();

	virtual int getPoints() const = 0;

	void update();
	void render();
private:
	int direction;
};

class EnemyType1 : public Enemy{
public:
	EnemyType1(int, int);
	int getPoints() const override;
};


class EnemyType2 : public Enemy {
public:
	EnemyType2(int, int);
	int getPoints() const override;
};


class EnemyType3 : public Enemy {
public:
	EnemyType3(int, int);
	int getPoints() const override;
};


class EnemyType4 : public Enemy {
public:
	EnemyType4(int, int);
	int getPoints() const override;
};

#endif