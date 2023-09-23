#ifndef FILL_H
#define FILL_H

#include "point2d.h"
#include <SDL2/SDL_render.h>

void fillTopFlatTriangle(SDL_Renderer* renderer, const Point2D& p1, const Point2D& p2, const Point2D& p3);
void fillBotFlatTriangle(SDL_Renderer* renderer, const Point2D& p1, const Point2D& p2, const Point2D& p3);
void fillTriangle(SDL_Renderer* renderer, const Point2D& point1, const Point2D& point2, const Point2D& point3);

#endif
