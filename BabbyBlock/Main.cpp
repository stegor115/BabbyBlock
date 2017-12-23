#include <iostream>
#include <SDL.h>
#undef main //Because SFL_main.h is included.

int main() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "REEE" << SDL_GetError() << std::endl;
	}
	return EXIT_SUCCESS;
}
