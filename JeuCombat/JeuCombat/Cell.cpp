#include "Cell.h"

Cell::Cell(int hp, bool isJ1, int range, int attackPower, int moveSpeed)
    : hp(hp), maxHp(hp), isJ1(isJ1), range(range), attackPower(attackPower), moveSpeed(moveSpeed) {
}

bool Cell::IsEmpty() const {
    return true;
}

int Cell::GetHp() const {
    return hp;
}

bool Cell::GetPlayer() const {
    return isJ1;
}

int Cell::GetRange() const {
    return range;
}

int Cell::GetAttackPower() const {
    return attackPower;
}

bool Cell::TakeDamage(int damage) {
    hp -= damage;
    return hp <= 0;
}

int Cell::DistanceSquared(int r1, int c1, int r2, int c2) {
    int dr = r1 - r2;
    int dc = c1 - c2;
    return dr * dr + dc * dc;
}

int Cell::GetMoveSpeed() const {
    return moveSpeed;
}

bool Cell::CanMoveTo(int sourceRow, int sourceCol, int targetRow, int targetCol) const {
    int distSq = DistanceSquared(sourceRow, sourceCol, targetRow, targetCol);
    return distSq <= moveSpeed * moveSpeed;
}