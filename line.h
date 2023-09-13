#ifndef LINE_H
#define LINE_H

#include "point3d.h"
#include "camera.h"
#include <SDL2/SDL_render.h>

struct Line
{
	Point3D start {};
	Point3D end {};
};

void drawLine(SDL_Renderer* renderer, const Camera& camera, const Line& line);

#endif
