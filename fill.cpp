#include "fill.h"
#include "point2d.h"
#include <SDL2/SDL_render.h>
#include <algorithm>
#include <iostream>

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
		Point2D midpoint {(p1.x + ((p2.y - p1.y) / (p3.y - p1.y)) * (p3.x - p1.x)), p2.y};
		fillBotFlatTriangle(renderer, p1, midpoint, p2);
		fillTopFlatTriangle(renderer, p2, midpoint, p3);
	}
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
}

void fillTopFlatTriangle(SDL_Renderer* renderer, const Point2D& p1, const Point2D& p2, const Point2D& p3)
{
	float cur1 {p3.x};
	float cur2 {p3.x};

	float slope1 {(p3.x - p1.x)/(p3.y - p1.y)};
	float slope2 {(p3.x - p2.x)/(p3.y - p2.y)};

	for (int i {static_cast<int>(p3.y)}; i < static_cast<int>(p1.y); ++i)
	{
		SDL_RenderDrawLine(renderer, cur1, i, cur2, i);
		cur1 += slope1;
		cur2 += slope2;
	}
}

void fillBotFlatTriangle(SDL_Renderer* renderer, const Point2D& p1, const Point2D& p2, const Point2D& p3)
{
	float cur1 {p1.x};
	float cur2 {p1.x};

	float slope1 {(p1.x - p2.x)/(p1.y - p2.y)};
	float slope2 {(p1.x - p3.x)/(p1.y - p3.y)};

	for (int i {static_cast<int>(p1.y)}; i >= static_cast<int>(p2.y); --i)
	{
		SDL_RenderDrawLine(renderer, cur1, i, cur2, i);
		cur1 -= slope1;
		cur2 -= slope2;
	}
}
