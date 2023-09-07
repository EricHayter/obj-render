#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <iostream>

void DrawCircle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius)
{
   const int32_t diameter = (radius * 2);

   int32_t x = (radius - 1);
   int32_t y = 0;
   int32_t tx = 1;
   int32_t ty = 1;
   int32_t error = (tx - diameter);

   SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
   while (x >= y)
   {
      //  Each of the following renders an octant of the circle
      SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

      if (error <= 0)
      {
         ++y;
         error += ty;
         ty += 2;
      }

      if (error > 0)
      {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }
   SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
   SDL_RenderPresent(renderer);
}

int main(int argc, char* args[]) {
	constexpr int SCREEN_WIDTH {960};
	constexpr int SCREEN_HEIGHT {960};

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
		DrawCircle(renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 50);
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	return 0;
}
