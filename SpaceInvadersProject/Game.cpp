#include "Game.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include "GameObject.h"
#include <conio.h>// za input






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



Game& Game::get() {
    static Game instance;
    return instance;
}

void Game::initializeEnemies() {
    enemies.clear();
    int spacing = 6;
    for (int i = 0; i < 10; ++i) {
        if (level == 1) enemies.push_back(new EnemyType1(10 + spacing * i, 3));
        if (level == 2) enemies.push_back(new EnemyType2(10 + spacing * i, 3));
        if (level == 3) enemies.push_back(new EnemyType3(10 + spacing * i, 3));
    }
    if (level == 3) {
        for (int i = 0; i < 5; ++i)
            enemies.push_back(new EnemyType4(15 + spacing * i, 5));
    }
}

void Game::input() {
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
        case 'a': case 'A': player.moveLeft(); break;
        case 'd': case 'D': player.moveRight(); break;
        case ' ': player.shoot(); break;
        }
    }
}

void Game::update() {
}

void Game::render() {
    for (int i = 0; i < POLE_ROWS; i++)
    {
        cout << "=";
    }
    cout << endl;
    cout << "Lives: " << player.getLives() << "   Level: " << this->level << "    Score: " << player.getScore() << endl;
    for (int i = 0; i < POLE_ROWS; i++) cout << "=";
    cout << endl;

}
void Game::run() {

    Player newPlayer(0, 0, '*', YELLOW, 3, 0);
    player = newPlayer;
    render();

    system("pause");
}