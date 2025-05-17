#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : GameObject{
public:
	Player(int = 0, int = 0, char = ' ', COLORS = WHITE, int = 0, int = 0);
	Player(const Player&);
	virtual ~Player();
	Player& operator=(const Player&);

	void moveLeft();
	void moveRight();
	void shoot();

	int getLives()const;
	int getScore()const;
	void setLives(int);
	void setScore(int);

	Player& operator+(int); //score+10
	Player& operator-(int);

private:
	int lives;
	int score;
};

void operator+(int lhs, Player& rhs); //10+score
void operator-(int lhs, Player& rhs);

#endif