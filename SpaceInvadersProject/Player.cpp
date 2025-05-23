#include "Player.h"
#include "Game.h"
#include "Bullet.h"
using namespace std;

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
	draw_char(' ', getY(), getX(), getColor(), BLACK);
	if (getX() > 1) setX(getX() - 1);

	//for testing: +10 score when moving left
	//setScore(getScore() + 10);
}
void Player::moveRight(){
	draw_char(' ', getY(), getX(), getColor(), BLACK);
	if (getX() < POLE_COLS-1) setX(getX() + 1);

	//for testing: -1 lives when moving right
	//setLives(getLives() - 1);
 }
void Player::shoot(){
	Game::get().addBullet(new Bullet(getX(), getY() - 1, '|', GREEN, -1));
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