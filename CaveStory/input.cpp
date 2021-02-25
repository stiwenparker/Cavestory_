#include "input.h"

//input class
//trzyma dane z klawiatury


//funkcja jest wywolana na poczatku kazdej klatki, zeby zwolnic przycisniete klawisze
void Input::beginNewFrame() {
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

//funkcja jest wywolywana kiedy przycisk zostal wcisniety
void Input::keyDownEvent(const SDL_Event& event) {
	this->_pressedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = true;
}

//ta funkcja jest wywolywana kiedy przycisk zostal puszczony
void Input::keyUpEvent(const SDL_Event& event) {
	this->_releasedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = false;

}

//sprawdza czy konkretny przycisk byl wcisniety w tej klatce
bool Input::wasKeyPressed(SDL_Scancode key) {
	return this->_pressedKeys[key];
}

//sprawdza czy konkretny przycisk byl puszczony w tej klatce
bool Input::wasKeyReleased(SDL_Scancode key) {
	return this->_releasedKeys[key];
}

//sprawdza czy konkretny przycisk jest obecnie trzymany
bool Input::isKeyHeld(SDL_Scancode key) {
	return this->_heldKeys[key];
}