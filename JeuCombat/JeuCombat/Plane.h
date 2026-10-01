#pragma once
#include "Cell.h"

class Plane : public Cell
{
public:
    Plane(bool isJ1 = true);

    bool Attack(Cell* target, int sourceRow, int sourceCol, int targetRow, int targetCol) override;
    bool CanAttack(int sourceRow, int sourceCol, int targetRow, int targetCol) const override;
    bool IsEmpty() const override { return false; }
    bool IsNeutral() const override { return false; }
};