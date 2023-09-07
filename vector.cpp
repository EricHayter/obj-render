#include "point.h"
#include <array>

using Vector3D = std::array<float, 3>;

void getVector(Vector3D& v, const Point& start, const Point& end)
{
	v[0] = end.x - start.x;
	v[1] = end.y - start.y;
	v[2] = end.z - start.z;
}
