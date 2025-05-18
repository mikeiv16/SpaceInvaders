#include "GameObject.h"


//pomoshten kod
void GameObject::draw_char(char ch, int y, int x, COLORS foreground_color, COLORS background_color) {
	HANDLE hConsoleOutput = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CHAR_INFO ch_info;
	//ch_info.Char.AsciiChar = ch; //izpolzvame UniCodeChar vmesto Ascii char za da moje direktno da se podava symbol kogato se vika funkciqta
	ch_info.Char.UnicodeChar = ch;
	ch_info.Attributes = foreground_color | (background_color << 4);

	COORD buf_size = { 1, 1 };
	COORD buf_coord = { 0, 0 };
	SMALL_RECT screen_pos = { x, y, x + 1, y + 1 };
	::WriteConsoleOutput(hConsoleOutput, &ch_info, buf_size, buf_coord, &screen_pos);
}

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