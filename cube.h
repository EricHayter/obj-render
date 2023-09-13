#ifndef CUBE_H
#define CUBE_H

#include <SDL2/SDL_render.h>
#include "camera.h"
#include "point3d.h"

void projectCube(SDL_Renderer* renderer,const Camera& camera, Point3D& p, const int length);

#endif
