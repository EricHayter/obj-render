#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "point.h"
#include <array>

using Vector3D = std::array<float, 3>;
Vector3D getVector(const Point& start, const Point& end);

#endif
