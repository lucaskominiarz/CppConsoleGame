#pragma once
#include "Cell.h"

class BomberPlane : public Cell {
private:
    int explosionRadius;

public:
    BomberPlane(bool isJ1);
    bool CanAttack(int sourceRow, int sourceCol, int targetRow, int targetCol) const;
    bool Attack(Cell* target, int sourceRow, int sourceCol, int targetRow, int targetCol) override;
    void Explode(Cell* grid[], int gridSize, int centerRow, int centerCol);
    bool IsEmpty() const override { return false; }
    bool IsNeutral() const override { return false; }
};