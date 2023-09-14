#include "cube.h"

#include "projection.h"
#include "line.h"
#include "camera.h"
#include <SDL2/SDL_render.h>

void projectCube(SDL_Renderer* renderer, const Camera& camera, const Point3D& p, const int l)
{
	// height (t/b)
	// side (l/r)
	// depth (b/f)

	Point3D blf {p};
	Point3D brf {p.x + l, p.y, p.z};
	Point3D blb {p.x, p.y, p.z + l};
	Point3D brb {p.x + l, p.y, p.z + l};
	Point3D tlf {p.x, p.y + l, p.z};
	Point3D trf {p.x + l, p.y + l, p.z};
	Point3D tlb {p.x, p.y + l, p.z + l};
	Point3D trb {p.x + l, p.y + l, p.z + l};

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	projectLine(renderer, camera, {blf, brf});
	projectLine(renderer, camera, {blf, blb});
	projectLine(renderer, camera, {blb, brb});
	projectLine(renderer, camera, {brf, brb});

	projectLine(renderer, camera, {blf, tlf});
	projectLine(renderer, camera, {brf, trf});
	projectLine(renderer, camera, {blb, tlb});
	projectLine(renderer, camera, {brb, trb});

	projectLine(renderer, camera, {tlf, trf});
	projectLine(renderer, camera, {tlf, tlb});
	projectLine(renderer, camera, {tlb, trb});
	projectLine(renderer, camera, {trf, trb});


	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
}
