#ifndef CAMERA_H
#define CAMERA_H

#include "point3d.h"
#include <math.h>

using Radians = float;

struct Camera
{
	Point3D position {};
	Point3D displayPosition {};
					   	// rotation around x axis should remain 0 as we
					   	// don't intend to use roll
	Radians yaw {}; 	// rotation around z axis [0, 2pi]
	Radians pitch {}; 	// rotation around y axis [0, pi]
						//
};

#endif
