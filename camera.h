#ifndef CAMERA_H
#define CAMERA_H

#include "point.h"
#include <math.h>

constexpr float FOV {M_PI/2};
using Radians = float;

struct Camera
{
	Point position {};
	Radians yaw {};
	Radians pitch {};
};

#endif
