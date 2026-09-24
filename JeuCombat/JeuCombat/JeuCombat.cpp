#include <iostream>
#include "Visual.h"
#include "Cell.h"

constexpr int gridSize = 20;
Cell grid[gridSize][gridSize]{ Cell() };
Visual visual;

bool j1Playing;
bool win;

void GameLoop() {
    int columnInput;
    int rowInput;
    while (!win) {
        visual.Draw(&grid[0][0], gridSize);
        std::cout << "Colonne : ";
        std::cin >> columnInput;
        std::cout << std::endl << "Ligne : ";
        std::cin >> rowInput;
        Cell selectedCell = grid[columnInput][rowInput];
        // check si la cellule est d'un certain type et si le joueur a acces si oui montrer ses stats et l'attaque possible 
        // la fonction attaque et tout faudrais les mettre directement dans avion et drone 
    }
}


int main(){

    grid[5][7] = Plane();
    GameLoop();
    return 0;
}

