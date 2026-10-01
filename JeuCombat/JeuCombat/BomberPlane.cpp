#include "BomberPlane.h"
#include <iostream>

BomberPlane::BomberPlane(bool isJ1) : Cell(50, isJ1, 7, 50, 1), explosionRadius(3) {
}

bool BomberPlane::CanAttack(int sourceRow, int sourceCol, int targetRow, int targetCol) const {
    int distSq = DistanceSquared(sourceRow, sourceCol, targetRow, targetCol);
    return distSq <= range * range;
}

void BomberPlane::Explode(Cell* grid[], int gridSize, int centerRow, int centerCol) {
    std::cout << "Une bombe a explose en (" << centerRow << ", " << centerCol << ")\n";
    for (int r = centerRow - explosionRadius; r <= centerRow + explosionRadius; ++r) {
        for (int c = centerCol - explosionRadius; c <= centerCol + explosionRadius; ++c) {
            if (r >= 0 && r < gridSize && c >= 0 && c < gridSize) {
                int dr = r - centerRow;
                int dc = c - centerCol;
                if (dr * dr + dc * dc <= explosionRadius * explosionRadius) {
                    Cell* cell = grid[r * gridSize + c];
                    if (cell != nullptr && !cell->IsEmpty()) {
                        cell->TakeDamage(attackPower);
                        std::cout << "Unite en (" << r << ", " << c << ") touchee\n";
                    }
                }
            }
        }
    }
}

bool BomberPlane::Attack(Cell* target, int sourceRow, int sourceCol, int targetRow, int targetCol) {
    if (!CanAttack(sourceRow, sourceCol, targetRow, targetCol)) {
        return false;
    }
    return true;
}