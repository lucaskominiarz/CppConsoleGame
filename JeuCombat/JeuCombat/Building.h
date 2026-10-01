#pragma once
#include "Cell.h"

class Building : public Cell {
public:
    Building(bool isJ1 = false);

    bool IsEmpty() const override { return false; }
    bool Attack(Cell* target, int sourceRow, int sourceCol, int targetRow, int targetCol) override;
    bool CanAttack(int sourceRow, int sourceCol, int targetRow, int targetCol) const override;
    bool IsNeutral() const override { return true; }
};