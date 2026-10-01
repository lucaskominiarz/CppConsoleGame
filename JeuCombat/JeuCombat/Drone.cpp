#include "Drone.h"
Drone::Drone(bool isJ1) : Cell(50, isJ1, 3, 25, 3) {
}

bool Drone::CanAttack(int sourceRow, int sourceCol, int targetRow, int targetCol) const {
    int distSq = DistanceSquared(sourceRow, sourceCol, targetRow, targetCol);
    return distSq <= range * range;
}

bool Drone::Attack(Cell* target, int sourceRow, int sourceCol, int targetRow, int targetCol) {
    if (!target || target->IsEmpty() || target->GetPlayer() == isJ1 && !target->IsNeutral()) {
        return false;
    }

    if (CanAttack(sourceRow, sourceCol, targetRow, targetCol)) {
        target->TakeDamage(attackPower);
        return true;
    }
    return false;
}