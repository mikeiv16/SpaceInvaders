#include "Game.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include "GameObject.h"
#include <iostream>
#include <sstream>
#include <conio.h> // za input

Game& Game::get() {
    static Game instance;
    return instance;
}


void Game::initializeEnemies() {

    //izchistvane na enemytata kato se smeni levela
	for (auto e : enemies) {
		e->draw_char(' ', e->getY(), e->getX(), e->getColor(), BLACK);
        delete e;
	}
    enemies.clear();


    int spacing = 4;
    switch (level) {
    case 1: {
        for (int i = 0; i < 10; i++)
        {
            enemies.push_back(new EnemyType1(10 + spacing * i, 3));
            enemies.push_back(new EnemyType1(15 + spacing * i, 5));
            enemies.push_back(new EnemyType1(10 + spacing * i, 7));
        }
        break;
    }
    case 2: {
        for (int i = 0; i < 10; i++) {
            enemies.push_back(new EnemyType2(10 + spacing * i, 3));
            enemies.push_back(new EnemyType3(15 + spacing * i, 5));
        }

        break;
    }
    case 3: {
        for (int i = 0; i < 8; i++)
        {
            enemies.push_back(new EnemyType4(10 + spacing + 3 * i, 3));
            enemies.push_back(new EnemyType3(15 + spacing + 4 * i, 5));
            enemies.push_back(new EnemyType2(10 + spacing + 4 * i, 7));
            enemies.push_back(new EnemyType1(15 + spacing + 4* i, 9));
        }
        break;
        }
    }
}

void Game::input() {
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
            case 'a': case 'A': player.moveLeft(); break;
            case 'd': case 'D': player.moveRight(); break;
            case ' ': {
                addBullet(new Bullet(player.getX(), player.getY() -1, '|', GREEN, -1));
				break;
            }
        }
    }
}

void Game::update() {
    player.draw_char(player.getSymbol(), player.getY(), player.getX(), player.getColor(), YELLOW);
    enemyCooldown++;
    bulletCooldown++;
    int lvlCooldown = 0;


    if (bulletCooldown > 25 && !(enemies.empty())) {
        int randomShooter = rand() % enemies.size();
        Enemy* shooters = dynamic_cast<Enemy*>(enemies[randomShooter]);
        Bullet* bullet = new Bullet(shooters->getX(), shooters->getY() + 1, 'x', RED, 1);
        addBullet(bullet);
        bulletCooldown = 0;
    }
    
    switch (level) {
    case 1: lvlCooldown = 100; break;
	case 2: lvlCooldown = 65; break;
	case 3: lvlCooldown = 40; break;
    } //poneje na vseki level strelqt po-burzo i se dvijat po-burzo, ima razlichen cooldown za vseki level

    if (enemyCooldown > lvlCooldown) {
        for (auto enemy : enemies) {
            enemy->draw_char(' ', enemy->getY(), enemy->getX(), enemy->getColor(), BLACK); //mahane na predishniq render na enemy-to
            enemy->setY(enemy->getY() + 1);
            enemy->render();

           

            //addBullet(new Bullet(enemy->getX(), enemy->getY() + 1, 'x', RED, 1));

            if (enemy->getY() >= POLE_ROWS - 2) {
                isRunning = false;
                system("cls");
                cout << "Game Over!" << endl;
                break;
            }

        }
        enemyCooldown = 0;
    }
    
    
    for (int i = static_cast<int>(bullets.size()) - 1; i >= 0; --i) {
        Bullet* b = dynamic_cast<Bullet*>(bullets[i]);
        if (!b) continue;
        b->draw_char(' ', b->getY(), b->getX(), b->getColor(), BLACK);
        b->update();
        if (b->getY() < 3) {
            delete b;
            bullets.erase(bullets.begin() + i);
        }
        else {
            b->render();
        }
    }

}

void Game::checkLevel() {
    if (player.getLives() <= 0) {
        isRunning = false;
        system("cls");
		cout << "No more lives left!\nGame Over!" << endl;
    }

    if (level == 1 && player.getScore() >= 200) {
        level++;
        player.setScore(0);
        initializeEnemies();
    }
    else if (level == 2 && player.getScore() >= 500) {
        level++;
        player.setScore(0);
        initializeEnemies();
    }
    else if (player.getScore() >= 300) {
        if (!gotExtraLife) {
            player.setLives(player.getLives() + 1);
            gotExtraLife = true;
        }
    }
    else if (level == 3 && player.getScore() >= 700)
    {
        cout << "test";
        isRunning = false;
        system("cls");
		cout << "You win!" << endl;
    }

}

void Game::checkCollisions() {

    for (int i = static_cast<int>(bullets.size()) - 1; i >= 0; --i) {
        Bullet* bullet = dynamic_cast<Bullet*>(bullets[i]);
        if (!bullet) continue;
        int bx = bullet->getX();
        int by = bullet->getY();
        for (int j = static_cast<int>(enemies.size()) - 1; j >= 0; --j) {
            Enemy* enemy = dynamic_cast<Enemy*>(enemies[j]);
            if (!enemy) continue;
            if (enemy->getX() == bx && enemy->getY() == by) {
                bullet->draw_char(' ', by, bx, bullet->getColor(), BLACK);
                enemy->draw_char(' ', enemy->getY(), enemy->getX(), enemy->getColor(), BLACK);
                player + enemy->getPoints();
                delete bullet;
                bullets.erase(bullets.begin() + i);
                delete enemy;
                enemies.erase(enemies.begin() + j);
                break;
            }
            else if(player.getX() == bx && player.getY() == by)  {
				player.setLives(player.getLives() - 1);
                break;
            }
        }
    }
    for (int j = static_cast<int>(enemies.size()) - 1; j >= 0; --j) {
        Enemy* enemy = dynamic_cast<Enemy*>(enemies[j]);
        if (!enemy) continue;
        if (enemy->getX() == player.getX() && enemy->getY() == player.getY()) {
            enemy->draw_char(' ', enemy->getY(), enemy->getX(), enemy->getColor(), BLACK);
            player.setLives(player.getLives() - 1);
            delete enemy;
            enemies.erase(enemies.begin() + j);
        }
    }

}
void Game::initializeStatusBar(int lives, int level, int score) {

    ostringstream oss;
    for (int i = 0; i < POLE_COLS; i++) oss << "=";
    oss << "\n";
    oss << "\t\tLives: " << player.getLives() << "   Level: " << this->level << "    Score: " << player.getScore();
	oss << "\n";
    for (int i = 0; i < POLE_COLS; i++) oss << "=";
    oss << "\n";

    //BUG kogato se kachi level 2: score pishe primerno 800 a to e 80, pishe go zashtoto e 80 no sedi edna 0 ot minaliq level poneje e bilo tricifreno chislo

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
	cout << oss.str();


    //rendervat se vsichki enemyta za da moje v nachaloto kato se pusne programata da ne se chaka delay(cooldowna) predi da se vizualizirat purvite enemyta
    for (auto e : enemies) {
        e->render();
    }
}

void Game::render() {
    //razmer na console
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = { POLE_COLS, POLE_ROWS };
	SetConsoleScreenBufferSize(hConsole, bufferSize);
	SMALL_RECT windowSize = { 0, 0, POLE_COLS - 1, POLE_ROWS - 1 };
	SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

    //cursor hide:
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

	// white console -> SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);

	initializeStatusBar(player.getLives(), level, player.getScore());
   
	enemyCooldown = 0;
    bulletCooldown = 0;

    for (int i = 0; i < POLE_ROWS-4; i++) {
        for (int j = 0; j < POLE_COLS; j++) {
            cout << " ";
        }
        cout << endl;
    }

	player.setX(POLE_COLS / 2);
	player.setY(POLE_ROWS - 2);
	player.draw_char(player.getSymbol(), player.getY(), player.getX(), player.getColor(), YELLOW);
}
void Game::run() {
    
	Player newPlayer(0, 0, '*', YELLOW, 3, 0);
    player = newPlayer;
    level = 1;
    isRunning = 1;
	gotExtraLife = 0; //na level 2 pri 300 tochki igracha poluchava edin extra jivot

    render();
    initializeEnemies();

	while (isRunning) {
        initializeStatusBar(player.getLives(), level, player.getScore());
		input();
		update();
		checkCollisions();
        Sleep(50); //skorost na igracha (delay za 50ms)
        checkLevel();
    }
    system("pause");
}

void Game::addBullet(Bullet* bullet) {
    bullets.push_back(bullet);
}

void Game::addEnemy(Enemy* enemy) { 
    enemies.push_back(enemy); 
}