#include "Game.h"

//pomoshten kod
void draw_char(char ch, int y, int x, COLORS foreground_color, COLORS background_color) {
	HANDLE hConsoleOutput = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CHAR_INFO ch_info;
	ch_info.Char.AsciiChar = ch;
	ch_info.Attributes = foreground_color | (background_color << 4);

	COORD buf_size = { 1, 1 };
	COORD buf_coord = { 0, 0 };
	SMALL_RECT screen_pos = { x, y, x + 1, y + 1 };
	::WriteConsoleOutput(hConsoleOutput, &ch_info, buf_size, buf_coord, &screen_pos);
}


void Game::initializeEnemies(){}
void Game::input(){}
void Game::update(){}
void Game::checkCollisions(){}
void Game::render(){

	for (int i = 0; i < POLE_ROWS; i++)
	{
		cout << "=";
	}
	cout << endl;
	cout << "Lives: " << player.getLives() << "   Level: " << this->level << "    Score: " << player.getScore() << endl;
	for (int i = 0; i < POLE_ROWS; i++) cout << "=";
	cout << endl;

}
void Game::run(){

	Player newPlayer(0, 0, '*', YELLOW, 3, 0);
	player = newPlayer;
	render();

	system("pause");
}