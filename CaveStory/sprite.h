#ifndef SPRITE_H
#define SPRITE_H
#define SDL_MAIN_HANDLED
#include <SDL.h>

#include <string>

class Graphics;

/* Sprite class
 * Holds all information for individual sprites
 */

class Sprite {
public:
	Sprite();

		//Sends a sprite to Graphics class object
	Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height,
			float posX, float posY);
	virtual ~Sprite();
	virtual void update();
		//Sends graphics class object with position of sprite to draw function
	void draw(Graphics &graphics, int x, int y);
private:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;

	float _x, _y;
};


#endif
