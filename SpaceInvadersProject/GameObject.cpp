#include "GameObject.h"

GameObject::GameObject(int x, int y, char symbol, COLORS color) : x(x), y(y), symbol(symbol), color(color){}
GameObject::GameObject(const GameObject& rhs) : x(rhs.x), y(rhs.y), symbol(rhs.symbol), color(rhs.color){}
GameObject::~GameObject(){}
GameObject& GameObject::operator=(const GameObject& rhs) {
	if (this != &rhs) {
		x = rhs.x;
		y = rhs.y;
		symbol = rhs.symbol;
		color = rhs.color;
	}
	return *this;
}


void GameObject::update(){

}
void GameObject::render(){

}

int GameObject::getX()const{
	return x;
}
int GameObject::getY()const{
	return y;
}
char GameObject::getSymbol()const{
	return symbol;
}
COLORS GameObject::getColor()const{
	return color;
}

void GameObject::setX(int x) {

	this->x = x;
}
void GameObject::setY(int y) {
	this->y = y;
}
void GameObject::setSymbol(char symbol) {
	this->symbol = symbol;
}
void GameObject::setColor(COLORS color) {
	this->color = color;
}