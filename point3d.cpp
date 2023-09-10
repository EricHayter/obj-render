#include "point3d.h"
#include "point2d.h"
#include "camera.h"
#include <cmath>

Point2D getPointProjection(const Point3D& point, const Camera& camera)
{
	Point3D cPos {camera.position};

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
