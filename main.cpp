#include "constants.h"
#include "camera.h"
#include "point3d.h"
#include "projection.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#include <iostream>
#include <array>
#include <cmath>

int main(int argc, char* args[]) {
	std::cout << "Hello world!";

	Point3D cameraPosition {0.0f, 0.0f, 0.0f};
	Point3D displayPosition {0.0f, 0.0f, 0.0f};
	Camera camera {cameraPosition, displayPosition, 0.0f, 0}; // might need to be pi/2
	Point3D point {100, 300, 100};
	Point3D point2 {100, 200, 100};
	Line line {point, point2};

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

		projectLine(renderer, line, camera);

		SDL_RenderPresent(renderer);
		SDL_Delay(5000);
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	return 0;
}
