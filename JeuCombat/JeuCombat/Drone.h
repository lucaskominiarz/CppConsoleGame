#pragma once
#include "Cell.h"
class Drone : public Cell
{
public:
    Drone(bool isJ1 = true);

    bool Attack(Cell* target, int sourceRow, int sourceCol, int targetRow, int targetCol) override;
    bool CanAttack(int sourceRow, int sourceCol, int targetRow, int targetCol) const override;
    bool IsEmpty() const override { return false; }
};