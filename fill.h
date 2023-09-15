#ifndef FILL_H
#define FILL_H

#include "point2d.h"
#include <SDL2/SDL_render.h>

void fillTopFlatTriangle(SDL_Renderer* renderer, const Point2D& p1, const Point2D& p2, const Point2D& p3);

#endif
