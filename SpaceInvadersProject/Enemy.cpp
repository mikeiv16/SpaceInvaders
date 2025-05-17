#include "Enemy.h"

Enemy::Enemy(int x, int y, char symbol, COLORS color, int direction) : GameObject(x, y, symbol, color), direction(direction){}
Enemy::Enemy(const Enemy& rhs) : GameObject(rhs), direction(rhs.direction){}
Enemy& Enemy::operator=(const Enemy& rhs){
	if (this != &rhs) {
		GameObject::operator=(rhs);
		direction = rhs.direction;
	}
	return *this;
}
Enemy::~Enemy(){}

void Enemy::update(){}
void Enemy::render(){}