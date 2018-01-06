//Keeps track of keyboard state, eventually mouse state.
#include "input.h"

//Voids --------------------------------------------------------------------
void Input::beginNewFrame() { //Resets keys no longer relevant
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

void Input::keyDownEvent(const SDL_Event& event) { //When a key has been pressed
	this->_pressedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = true;
}

void Input::keyUpEvent(const SDL_Event& event) { //When a key has been released
	this->_releasedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = false;
}

//Booleans --------------------------------------------------------------------

bool Input::wasKeyPressed(SDL_Scancode key) {
	return this->_pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key) {
	return this->_releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key) {
	return this->_heldKeys[key];
}