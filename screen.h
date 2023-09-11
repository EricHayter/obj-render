#ifndef CONSTANTS_H
#define CONSTANTS_H

// should I remap point2d specifically?

constexpr float SCREEN_HEIGHT {960};
constexpr float SCREEN_WIDTH {960};

constexpr float MID_H {SCREEN_HEIGHT / 2};
constexpr float MID_W {SCREEN_WIDTH / 2};

float remapX(float x);
float remapY(float y);

#endif
