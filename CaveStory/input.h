#pragma once
#ifndef INPUT_H
#define INPUT_H

#include <map>
#include <SDL.h>

class Input {
	public:
		void beginNewFrame();
		void keyUpEvent(const SDL_Event& event);
		void keyDownEvent(const SDL_Event& event);

		bool wasKeyPressed(SDL_Scancode key);
		bool wasKeyReleased(SDL_Scancode key);
		bool isKeyHeld(SDL_Scancode key);


	private:
		//wyszukuje klawisz ktory jest obecnie: trzymany, wcisniety, puszczony
		std::map<SDL_Scancode, bool> _heldKeys; 
		std::map<SDL_Scancode, bool> _pressedKeys;
		std::map<SDL_Scancode, bool> _releasedKeys;
};

#endif