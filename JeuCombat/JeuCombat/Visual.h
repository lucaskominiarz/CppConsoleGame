#pragma once
#include "Cell.h"

class Visual {
public:
    void Draw(Cell* grid[], const int size, bool isJ1Turn);

private:
    void RangeCircle(bool* range, const int size, int centerX, int centerY, int radius);
};