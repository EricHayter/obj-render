#ifndef POINT_H
#define POINT_H

#include "point2d.h"
#include "camera.h"

struct Point3D
{
	float x {};
	float y {};
	float z {};
};

Point2D getPointProjection(const Point3D& point, const Camera& camera);

#endif
