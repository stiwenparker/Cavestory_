#ifndef INPUT_H
#define INPUT_H
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <map>

class Input {
public:
		//beginNewFrame gets called at the beginning of every frame
		//to reset keys that are not used now
	void beginNewFrame();
		//This gets called when a key has been pressed
	void keyUpEvent(const SDL_Event& event);
		//This gets called when a key has been released
	void keyDownEvent(const SDL_Event& event);

		//Check if a certain key was pressed during the current frame
	bool wasKeyPressed(SDL_Scancode key);
		//Check if a certain key was released during the current frame
	bool wasKeyReleased(SDL_Scancode key);
		//Check if a certain key was held during the current frame
	bool isKeyHeld(SDL_Scancode key);
private:
		//Stores a value of key states
	std::map<SDL_Scancode, bool> _heldKeys;
	std::map<SDL_Scancode, bool> _pressedKeys;
	std::map<SDL_Scancode, bool> _releasedKeys;
};

#endif
