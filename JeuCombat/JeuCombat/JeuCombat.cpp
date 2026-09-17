#include <iostream>
#include "Visual.h"
#include "Cell.h"

int main(){

    constexpr int gridSize = 20;
    Visual visual;
    Cell grid[gridSize][gridSize]{Cell()};
    grid[5][7] = Plane();
    visual.Draw(&grid[0][0], gridSize);

    delete[] grid;
    return 0;
}
