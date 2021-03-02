#ifndef GAME_H
#define GAME_H

#include "animatedsprite.h"

class Graphics;

class Game {
public:
	Game();
	~Game();
private:
	//main gameloop 
	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	AnimatedSprite _player;
};

#endif
