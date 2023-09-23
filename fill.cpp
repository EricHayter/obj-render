#include "fill.h"
#include "point2d.h"
#include <SDL2/SDL_render.h>

// implementation of the simple flat top/bottom triangle
void fillTriangle(SDL_Renderer* renderer, const Point2D& point1, const Point2D& point2, const Point2D& point3)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	Point2D p1 {point1};
	Point2D p2 {point2};
	Point2D p3 {point3};

	// sort them (v1 is highest, v3 is lowest)
	if (p1.y < p2.y)
		std::swap(p1, p2);
	if (p1.y < p3.y)
		std::swap(p1, p3);
	if (p2.y < p3.y)
		std::swap(p2, p3);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	if (p1.y == p2.y)
	{
		fillTopFlatTriangle(renderer, p1, p2, p3);
	}
	else if (p2.y == p3.y)
	{
		fillBotFlatTriangle(renderer, p1, p2, p3);
	}
	else
	{
		float xCoord {p3.x};
		float slope {(p1.x - p3.x)/(p1.y - p3.y)};
		for (float i {p3.y}; i < p2.y; ++i) // idk about this lol
		{										// might be a bit too much voodoo
			xCoord += slope;
		}
		fillBotFlatTriangle(renderer, point1, {xCoord, point2.y}, point2);
		fillTopFlatTriangle(renderer, point2, {xCoord, point2.y}, point3);
	}
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
}

void fillTopFlatTriangle(SDL_Renderer* renderer, const Point2D& p1, const Point2D& p2, const Point2D& p3)
{
	float cur1 {static_cast<float>(p3.x)};
	float cur2 {static_cast<float>(p3.x)};

	float slope1 {static_cast<float>(p3.x - p1.x)/(p3.y - p1.y)};
	float slope2 {static_cast<float>(p3.x - p2.x)/(p3.y - p2.y)};

	for (float i {p3.y}; i < p1.y; ++i)
	{
		SDL_RenderDrawLine(renderer, cur1, i, cur2, i);
		cur1 += slope1;
		cur2 += slope2;
	}
}

void fillBotFlatTriangle(SDL_Renderer* renderer, const Point2D& p1, const Point2D& p2, const Point2D& p3)
{
	float cur1 {static_cast<float>(p1.x)};
	float cur2 {static_cast<float>(p1.x)};

	float slope1 {static_cast<float>(p1.x - p2.x)/(p1.y - p2.y)};
	float slope2 {static_cast<float>(p1.x - p3.x)/(p1.y - p3.y)};

	for (float i {p1.y}; i > p2.y; --i)
	{
		SDL_RenderDrawLine(renderer, cur1, i, cur2, i);
		cur1 += slope1;
		cur2 += slope2;
	}
}
