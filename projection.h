#ifndef PROJECTION_H
#define PROJECTION_H

#include "point3d.h"
#include "point2d.h"
#include "line.h"
#include "camera.h"

#include "SDL2/SDL_render.h"

void projectPoint(SDL_Renderer* renderer, const Point3D& point, const Camera& camera);

void projectLine(SDL_Renderer* renderer, const Line& line, const Camera& camera);

Point2D findProjection(const Point3D& point, const Camera& camera);

#endif
