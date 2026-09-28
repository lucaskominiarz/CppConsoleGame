#include <iostream>
#include "Visual.h"
#include "Cell.h"

constexpr int gridSize = 20;
Cell* grid[gridSize * gridSize]{ nullptr };
Visual visual;
bool win = false;
bool isJ1 = true;
Cell* GetCell(int row, int col) {
    return grid[row * gridSize + col];
}

void SetCell(int row, int col, Cell* cell) {
    grid[row * gridSize + col] = cell;
}

int main() {
    SetCell(5, 7, new Plane());

    while (!win) {
        visual.Draw(grid, gridSize,isJ1);

        int rowInput, columnInput;
        std::cout << "Ligne : ";
        std::cin >> rowInput;
        std::cout << "Colonne : ";
        std::cin >> columnInput;

        Cell* selected = GetCell(rowInput, columnInput);
        if (dynamic_cast<Plane*>(selected)) {
            std::cout << "Avion selectionne\n";
        }
        else if (dynamic_cast<Drone*>(selected)) {
            std::cout << "Drone selectionne\n";
        }
        else
        {
            std::cout << "Cellule vide\n"; 
        }
        isJ1 = !isJ1;
    }
    for (int i = 0; i < gridSize * gridSize; ++i) {
        delete grid[i];
    }

    return 0;
}
