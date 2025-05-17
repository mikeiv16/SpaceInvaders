#include "Player.h"

Player::Player(int x, int y, char symbol, COLORS color, int lives, int score) : GameObject(x, y, symbol, color), lives(lives), score(score){}
Player::Player(const Player& rhs) : GameObject(rhs), lives(rhs.lives), score(rhs.score){}
Player::~Player(){}
Player& Player::operator=(const Player& rhs){
	if (this != &rhs) {
		GameObject::operator=(rhs);
		lives = rhs.lives;
		score = rhs.score;
	}
	return *this;
}

void Player::moveLeft(){

}
void Player::moveRight(){

 }
void Player::shoot(){

}

int Player::getLives()const{
	return lives;
}
int Player::getScore()const{
	return score;
}
void Player::setLives(int lives){
	this->lives = lives;
}
void Player::setScore(int score){
	this->score = score;
}

Player& Player::operator+(int rhs){
	score += rhs;
	return *this;
}
Player& Player::operator-(int rhs){
	score -= rhs;
	return *this;
}

void operator+(int lhs, Player& rhs) {
	rhs.setScore(rhs.getScore() + lhs);
}
void operator-(int lhs, Player& rhs) {
	rhs.setScore(rhs.getScore() - lhs);
}