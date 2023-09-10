#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "point3d.h"
#include <array>

using Vector3D = std::array<float, 3>;
Vector3D getVector(const Point3D& start, const Point3D& end);

#endif
