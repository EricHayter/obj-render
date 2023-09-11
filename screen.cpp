#include "screen.h"

float remapX(float x)
{
	return x + MID_W;
}

float remapY(float y)
{
	return MID_H - y;
}
