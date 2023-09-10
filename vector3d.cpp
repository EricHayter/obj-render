#include "vector3d.h"
#include "point3d.h"
#include <array>


Vector3D getVector(const Point3D& start, const Point3D& end)
{
	Vector3D v {};
	v[0] = end.x - start.x;
	v[1] = end.y - start.y;
	v[2] = end.z - start.z;
	return v;
}
