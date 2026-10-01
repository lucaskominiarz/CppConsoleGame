#include "HealerDrone.h"

HealerDrone::HealerDrone(bool isJ1) : Cell(40, isJ1, 3, 30, 3) {
}

bool HealerDrone::CanHeal(int sourceRow, int sourceCol, int targetRow, int targetCol) const {
    int distSq = DistanceSquared(sourceRow, sourceCol, targetRow, targetCol);
    return distSq <= range * range;
}
bool HealerDrone::CanAttack(int sourceRow, int sourceCol, int targetRow, int targetCol) const {
    return CanHeal(sourceRow, sourceCol, targetRow, targetCol);
}

bool HealerDrone::Attack(Cell* target, int sourceRow, int sourceCol, int targetRow, int targetCol) {
    if (!target || target->IsEmpty() || target->GetPlayer() != isJ1) {
        return false;
    }
    if (CanHeal(sourceRow, sourceCol, targetRow, targetCol)) {
        target->Heal(attackPower);
        return true;
    }
    return false;
}