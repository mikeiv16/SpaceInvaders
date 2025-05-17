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

void Enemy::update() {
	{
		setX(getX() + direction);
		if (getX() <= 0 || getX() >= POLE_ROWS - 2) {
			direction = -direction;
			setY(getY() + 1);
		}
	}
}
void Enemy::render(){
	draw_char(getSymbol(), getY(), getX(), getColor(), GREY);
}



EnemyType1::EnemyType1(int x, int y) : Enemy(x, y, '1', LIGHT_RED, 1) {
}
int EnemyType1::getPoints() const {
	return 10;
}

EnemyType2::EnemyType2(int x, int y) : Enemy(x, y, '2', LIGHT_BLUE, 1) {
}
int EnemyType2::getPoints() const {
	return 20;
}

EnemyType3::EnemyType3(int x, int y) : Enemy(x, y, '3', LIGHT_GREY, 1) {
}
int EnemyType3::getPoints() const {
	return 30;
}

EnemyType4::EnemyType4(int x, int y) : Enemy(x, y, '4', GREEN, 1) {
}
int EnemyType4::getPoints() const {
	return 40;
}