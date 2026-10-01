#include "Plane.h"

Plane::Plane(bool isJ1) : Cell(100, isJ1, 5, 35, 2) {
}

bool Plane::CanAttack(int sourceRow, int sourceCol, int targetRow, int targetCol) const {
    int distSq = DistanceSquared(sourceRow, sourceCol, targetRow, targetCol);
    return distSq <= range * range;
}

bool Plane::Attack(Cell* target, int sourceRow, int sourceCol, int targetRow, int targetCol) {
    if (!target || target->IsEmpty() || target->GetPlayer() == isJ1 && !target->IsNeutral()) {
        return false;
    }

    if (CanAttack(sourceRow, sourceCol, targetRow, targetCol)) {
        target->TakeDamage(attackPower);
        return true;
    }
    return false;
}
