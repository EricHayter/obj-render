#include "projection.h"

#include "constants.h"
#include "point3d.h"
#include "line.h"
#include "point2d.h"
#include "camera.h"

#include "SDL2/SDL_render.h"

/*
 * not quite right yet
 * the Y coordinated are incorrect with the way that we have them formatted
 * (1,1) at top right (-1, -1) bottom left
 * by default 0 is the top of the screen and 1 is the bottom
 * should scale by -1 then add half the height (or reverse)
 */

constexpr Point3D origin {0.0f, 0.0f, 0.0f};

void projectPoint(SDL_Renderer* renderer, const Point3D& point, const Camera& camera)
{
		Point2D projection {findProjection(point, camera)};
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderDrawPointF(renderer, MID_W + projection.x,
				MID_H + projection.y);
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
}

void projectLine(SDL_Renderer* renderer, const Line& line, const Camera& camera)
{
		Point2D start {findProjection(line.start, camera)};
		Point2D end {findProjection(line.end, camera)};
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderDrawLine(renderer, start.x + MID_W, end.x + MID_W, start.y + MID_H, end.y + MID_H);
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
}

Point2D findProjection(const Point3D& point, const Camera& camera)
{
	Point3D cPos {camera.position};
	if (cPos.x ==  origin.x && cPos.y == origin.y && cPos.z == origin.z &&
			camera.pitch == 0.0f && camera.yaw == 0.0f)
	{
		return {point.x , point.y};
	}


	float x {point.x - cPos.x};
	float y {point.y - cPos.y};
	float z {point.z - cPos.z};

	float cosx {std::cos(cPos.x)};
	float cosy {std::cos(cPos.y)};
	float cosz {std::cos(cPos.z)};

	float sinx {std::sin(cPos.x)};
	float siny {std::sin(cPos.y)};
	float sinz {std::sin(cPos.z)};

	float a {sinz*y + cosz*x};
	float b {cosz*y - sinz*x};
	float c {cosy*z + siny*a};

	float dx {cosy*a - siny*z};
	float dy {sinx*c + cosx*b};
	float dz {cosx*c - sinx*b};

	Point3D e {camera.displayPosition};
	Point2D projection {e.z/dz*dx + e.x, e.z/dz*dy +e.y};
	return projection;
}
