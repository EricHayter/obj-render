#include "cube.h"

#include "projection.h"
#include "line.h"
#include "camera.h"
#include <SDL2/SDL_render.h>

void projectCube(SDL_Renderer* renderer, const Camera& camera, Point3D& p, const int length)
{

	projectLine(renderer, camera, {p,{p.x + length, p.y, p.z}});
	projectLine(renderer, camera, {p,{p.x, p.y + length ,p.z}});
	projectLine(renderer, camera, {p,{p.x + length, p.y ,p.z}});
	projectLine(renderer, camera, {p,{p.x, p.y + length ,p.z}});

	p.z = p.z + length;

	projectLine(renderer, camera, {p,{p.x + length, p.y, p.z}});
	projectLine(renderer, camera, {p,{p.x, p.y + length ,p.z}});
	projectLine(renderer, camera, {p,{p.x + length, p.y ,p.z}});
	projectLine(renderer, camera, {p,{p.x, p.y + length ,p.z}});

	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
}
