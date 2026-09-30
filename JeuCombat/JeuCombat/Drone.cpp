#include "Drone.h"
Drone::Drone(bool isJ1)
    : Cell(50, isJ1, 2, 20, 2) {
}

bool Drone::CanAttack(int sourceRow, int sourceCol, int targetRow, int targetCol) const {
    int distSq = DistanceSquared(sourceRow, sourceCol, targetRow, targetCol);
    return distSq <= range * range;
}

bool Drone::Attack(Cell* target, int sourceRow, int sourceCol, int targetRow, int targetCol) { // faire un drone qui soigne
    if (!target || target->IsEmpty() || target->GetPlayer() == isJ1) {
        return false;
    }

    if (CanAttack(sourceRow, sourceCol, targetRow, targetCol)) {
        target->TakeDamage(attackPower);
        return true;
    }
    return false;
}