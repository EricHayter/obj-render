#include "camera.h"
#include "line.h"
#include "vector3d.h"
#include <SDL2/SDL_render.h>
#include <array>

void drawLine(SDL_Renderer* renderer, const Camera& camera, const Line& line)
{
	// find the projection
	// x y z
	Vector3D vectorA {};
	getVector(vectorA, line.start, line.end);
	Vector3D vectorB {};

	// create a line from the camera position to the end of the line
	getVector(vectorA, line.start, line.end);
	// vector projection
}
