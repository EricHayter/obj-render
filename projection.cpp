#include "projection.h"

#include "screen.h"
#include "point3d.h"
#include "line.h"
#include "point2d.h"
#include "camera.h"

#include "SDL2/SDL_render.h"

#include <iostream>

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
	projection.x = remapX(projection.x);
	projection.y = remapY(projection.y);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawPointF(renderer, projection.x,
			projection.y);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
}

void projectLine(SDL_Renderer* renderer, const Line& line, const Camera& camera)
{
	Point2D start {findProjection(line.start, camera)};
	Point2D end {findProjection(line.end, camera)};

	start.x = remapX(start.x);
	start.y = remapY(start.y);
	end.x = remapX(end.x);
	end.y = remapY(end.y);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawLine(renderer, start.x, start.y, end.x, end.y);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
}

Point2D findProjection(const Point3D& point, const Camera& camera)
{
	Point3D cPos {camera.position};
	//	if (cPos.x ==  origin.x && cPos.y == origin.y && cPos.z == origin.z &&
	//			camera.pitch == 0.0f && camera.yaw == 0.0f)
	//	{
	//		return {point.x , point.y};
	//	}
	float dx {};
	float dy {};
	float dz {};
	if (camera.yaw == 0.0f && camera.pitch == 0.0f)
	{
		std::cout << "Point at " << point.x << " " << point.y << " " << point.z << "\n";
		dx = point.x - cPos.x;
		dy = point.y - cPos.y;
		dz = point.z - cPos.z;
	}
	else
	{
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

		dx = cosy*a - siny*z;
		dy = sinx*c + cosx*b;
		dz = cosx*c - sinx*b;
	}

	Point3D e {camera.displayPosition};
	Point2D projection {e.z/dz*dx + e.x, e.z/dz*dy +e.y};
	return projection;
}
