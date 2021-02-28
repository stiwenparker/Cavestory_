#ifndef GRAPHICS_H
#define GRAPHICS_H

/* Graphics class
 * Holds all information dealing with graphics for the game
 */

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();

		//loads image into _spriteSheets, first checks if image is already loaded
		//then doesnt load it more than once
	SDL_Surface* loadImage(const std::string &filePath);

		//draws textures to certain part of a screen
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

		//renders stuff to the window
	void flip();

		//clears the screen
	void clear();

		//returns renderer
	SDL_Renderer* getRenderer() const;

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif
