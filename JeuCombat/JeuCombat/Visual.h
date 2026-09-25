#pragma once
#include <iostream>;
#include "Cell.h"
#include "Plane.h"
#include "Drone.h"


class Visual
{
public:
	void Draw(Cell* grid[], const int size);
	void RangeCircle(bool* fog, const int size, int centerX, int centerY, int radius);
};

