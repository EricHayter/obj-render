#include "fill.h"
#include "point2d.h"
#include <SDL2/SDL_render.h>

// implementation of the simple flat top/bottom triangle
void fillFlatTriangle(SDL_Renderer* renderer, const Point2D& p1, const Point2D& p2, const Point2D& p3)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	Point2D v1 {p1};
	Point2D v2 {p2};
	Point2D v3 {p3};

	// sort them
	if (v1.y < v2.y)
		std::swap(v1, v2);
	if (v1.y < v3.y)
		std::swap(v1, v3);
	if (v2.y < v3.y)
		std::swap(v2, v3);




	// find the functions of the slopes

	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
}

// implementation for the general case traingle
void fillTriangle(SDL_Renderer* renderer, const Point2D& p1, const Point2D& p2, const Point2D& p3)
