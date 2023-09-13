#include "screen.h"
#include "camera.h"
#include "point3d.h"
#include "projection.h"
#include "cube.h"
#include "line.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#include <iostream>
#include <array>
#include <cmath>

int main(int argc, char* args[]) {
	Point3D cameraPosition {0.0f, 0.0f, 0.0f};
	Point3D displayPosition {0.0f, 0.0f, MID_W};
	Camera camera {cameraPosition, displayPosition, 0.0f, 0.0f}; // might need to be pi/2
	Line line {{0, 0 , 100}, {0, 10, 100}};

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

		Point3D start {0, 0, 1000};
		Point3D end {start};
		end.z = 900;
		for (int i {0}; i < 5; ++i)
		{
			drawLine(renderer, camera, {start, end});
			start.x += 50;
			end.x += 50;
		}

		SDL_RenderPresent(renderer);
		SDL_Delay(500);
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	return 0;
}
