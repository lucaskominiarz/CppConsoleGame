#include "Building.h"

Building::Building(bool isJ1) : Cell(200, isJ1, 0, 0, 0) {
}

bool Building::CanAttack(int sourceRow, int sourceCol, int targetRow, int targetCol) const {
    return false;
}

bool Building::Attack(Cell* target, int sourceRow, int sourceCol, int targetRow, int targetCol) {
    return false;
}