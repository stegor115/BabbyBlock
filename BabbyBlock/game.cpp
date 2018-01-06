//This class holds all the information for the main game loop
#include <SDL.h>
#include <algorithm>
#include "game.h"
#include "graphics.h"
#include "input.h"

namespace {
	const int FPS = 60; //Only acceptable FPS
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;

}
Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event;

	int LAST_UPDATE_TIME = SDL_GetTicks();
	//Start game loop
	while (true) {
		input.beginNewFrame();
		if (SDL_PollEvent(&event)) {

			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) { //Checks if the key is being held down
					input.keyDownEvent(event);
				} //end repeating key if
			} //end SDL_KEYDOWN if

			else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}

			else if (event.type == SDL_QUIT) {
				return;
			} //end SDL_QUIT if 
		} //end PollEvent if

		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) { //Quits the games if escape is pressed
			return;
		} //end escape pressed if

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELASPED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::min(ELASPED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

	} //end while
} //end gameLoop

void Game::draw(Graphics &graphics) {

}

void Game::update(float elapsedTime) {

}