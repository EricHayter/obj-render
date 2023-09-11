#ifndef CONSTANTS_H
#define CONSTANTS_H

// should I remap point2d specifically?

constexpr float SCREEN_HEIGHT {960};
constexpr float SCREEN_WIDTH {960};

constexpr float MID_H {SCREEN_HEIGHT / 2};
constexpr float MID_W {SCREEN_WIDTH / 2};

int constexpr remapX(int x)
{
	return x + MID_W;
}

int constexpr reampY(int y)
{
	return MID_H - y;
}

#endif
