#ifndef PROJECTION_H
#define PROJECTION_H

#include "point3d.h"
#include "point2d.h"
#include "line.h"
#include "camera.h"

#include "SDL2/SDL_render.h"

void projectPoint(SDL_Renderer* renderer, const Camera& camera, const Point3D& point);
void projectLine(SDL_Renderer* renderer, const Camera& camera, const Line& line);
Point2D findProjection(const Camera& camera, const Point3D& point);

#endif
