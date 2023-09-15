#include "fill.h"
#include "point2d.h"
#include <SDL2/SDL_render.h>

// implementation of the simple flat top/bottom triangle
void fillTriangle(SDL_Renderer* renderer, const Point2D& p1, const Point2D& p2, const Point2D& p3)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	Point2D v1 {p1};
	Point2D v2 {p2};
	Point2D v3 {p3};

	// sort them (v1 is highest, v3 is lowest)
	if (v1.y < v2.y)
		std::swap(v1, v2);
	if (v1.y < v3.y)
		std::swap(v1, v3);
	if (v2.y < v3.y)
		std::swap(v2, v3);

	if (v1.y == v2.y)
	{
		// run the fillTopFlatTriangle function
	}
	else if (v2.y == v3.y)
	{
		// run the fillBottomFlatTriangle function
	}
	else
	{
		// generic case we will split our triangle
		// then call top and bottom on each part of spit
	}


	// find the functions of the slopes

	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
}

void fillTopFlatTriangle(SDL_Renderer* renderer, const Point2D& p1, const Point2D& p2, const Point2D& p3)
{
	int cur1 {p1.x};
	int cur2 {p2.x};

	float slope1 {static_cast<float>(p3.x - p1.x)/(p3.y - p1.y)};
	float slope2 {static_cast<float>(p3.x - p2.x)/(p3.y - p2.y)};

	// keep this for now replace later when inside the actual function
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	for (int i {p1.y}; i >= p3.y; --i)
	{
		cur1 -= slope1;
		cur2 -= slope2;
		SDL_RenderDrawLine(renderer, cur1, i, cur2, i);
	}

	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
}

void fillBotFlatTriangle(SDL_Renderer* renderer, const Point2D& p1, const Point2D& p2, const Point2D& p3)
{

}
