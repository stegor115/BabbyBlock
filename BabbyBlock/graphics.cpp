// This class holds all information related to graphics within the game
#include "SDL.h"
#include "graphics.h"

Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(800, 800, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Babby Block");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(this->_window);
}