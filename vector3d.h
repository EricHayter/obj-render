#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "point.h"
#include <array>

using Vector3D = std::array<float, 3>;
void getVector(Vector3D& v, const Point& start, const Point& end);

#endif
