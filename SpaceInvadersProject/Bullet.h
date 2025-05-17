#ifndef BULLET_H
#define BULLET_H
#include "GameObject.h"

class Bullet : public GameObject {
	public:
	Bullet(int = 0, int = 0, char = ' ', COLORS = LIGHT_GREY, int = 0);
	Bullet(const Bullet&);
	Bullet& operator=(const Bullet&);
	virtual ~Bullet();

	void update();
	void render();
private:
	int direction;
};

#endif