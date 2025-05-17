#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


//pomoshten kod za colors ot uslovieto za proekta
#include <windows.h>
#include <iostream>
using namespace std;

const int POLE_ROWS = 90;
const int POLE_COLS = 180;

enum COLORS {
    BLACK = 0,
    BLUE = FOREGROUND_BLUE,
    CYAN = FOREGROUND_BLUE | FOREGROUND_GREEN,
    GREEN = FOREGROUND_GREEN,
    RED = FOREGROUND_RED,
    BROWN = FOREGROUND_RED | FOREGROUND_GREEN,
    PURPLE = FOREGROUND_RED | FOREGROUND_BLUE,
    LIGHT_GREY = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN,
    GREY = 0 | FOREGROUND_INTENSITY,
    LIGHT_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    LIGHT_CYAN = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    LIGHT_GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    LIGHT_RED = FOREGROUND_RED | FOREGROUND_INTENSITY,
    YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    PINK = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    WHITE = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
};




class GameObject {

public:
    GameObject(int = 0, int = 0, char = ' ', COLORS = WHITE);
    GameObject(const GameObject&);
    virtual ~GameObject();
    GameObject& operator=(const GameObject&);

    virtual void update();
    virtual void render();
    
    int getX()const;
    int getY()const;
    char getSymbol()const;
    COLORS getColor()const;

    void setX(int);
    void setY(int);
    void setSymbol(char);
    void setColor(COLORS);

private:
	int x;
	int y;
	char symbol;
	COLORS color;

};

#endif