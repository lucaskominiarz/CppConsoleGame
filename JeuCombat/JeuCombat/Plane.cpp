#include "Plane.h"

Plane::Plane(bool isJ1)
    : Cell(100, isJ1, 4, 35, 3) {
}

bool Plane::CanAttack(int sourceRow, int sourceCol, int targetRow, int targetCol) const {
    int distSq = DistanceSquared(sourceRow, sourceCol, targetRow, targetCol);
    return distSq <= range * range;
}

bool Plane::Attack(Cell* target, int sourceRow, int sourceCol, int targetRow, int targetCol) { // faire 2e type de plane avec une attaque de zone
    if (!target || target->IsEmpty() || target->GetPlayer() == isJ1) {
        return false;
    }

    if (CanAttack(sourceRow, sourceCol, targetRow, targetCol)) {
        target->TakeDamage(attackPower);
        return true;
    }
    return false;
}
