#pragma once
#include "Cell.h"

class HealerDrone : public Cell {
public:
    HealerDrone(bool isJ1);
    bool IsEmpty() const override { return false; }
    bool CanHeal(int sourceRow, int sourceCol, int targetRow, int targetCol) const;
    bool Attack(Cell* target, int sourceRow, int sourceCol, int targetRow, int targetCol) override;
    bool CanAttack(int sourceRow, int sourceCol, int targetRow, int targetCol) const override;
    bool IsNeutral() const override { return false; }
};