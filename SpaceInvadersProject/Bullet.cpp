#include "Bullet.h"

Bullet::Bullet(int x, int y, char symbol, COLORS color, int direction) : GameObject(x, y, symbol, color), direction(direction){}
Bullet::Bullet(const Bullet& rhs) : GameObject(rhs), direction(rhs.direction){}
Bullet& Bullet::operator=(const Bullet& rhs){
	if (this != &rhs) {
		GameObject::operator=(rhs);
		direction = rhs.direction;
	}
	return *this;
}
Bullet::~Bullet(){}

void Bullet::update(){
	setY(getY() + direction);
}
void Bullet::render(){
	draw_char(getSymbol(), getY(), getX(), getColor(), WHITE);
}