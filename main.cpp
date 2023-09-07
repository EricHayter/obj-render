#include "camera.h"
#include "point.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <iostream>
#include <array>

int main(int argc, char* args[]) {
	constexpr int SCREEN_WIDTH {960};
	constexpr int SCREEN_HEIGHT {960};

	Point cameraPosition {};

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << stderr << "could not initilize sdl2: " << SDL_GetError() << "\n";
		return 1;
	}

	SDL_Window* window {};
	SDL_Renderer* renderer {};

	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);

	if (window == NULL) {
		std::cout << stderr << "could not create window :" << SDL_GetError() << "\n";
		return 1;
	}

	bool quit {false};
	SDL_Event event{};
	while (!quit)
	{
		if (event.type == SDL_QUIT)
			quit = true;
		SDL_RenderClear(renderer);

		SDL_Delay(1000/60);
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	return 0;
}
