#include "Visual.h"

#include <iostream>
#include <sstream>

void Visual::Draw(Cell* grid[], const int size) {
    system("cls");
    for (int i = 0; i < size; ++i) {
        std::cout << "|";
        for (int j = 0; j < size; ++j) {
            Cell* ptr = grid[i * size + j];

            if (dynamic_cast<Plane*>(ptr)) {
                std::cout << "p|";
            }
            else if (dynamic_cast<Drone*>(ptr)) {
                std::cout << "d|";
            }
            else {
                std::cout << "_|";
            }
        }
        std::cout << "\n";
    }
}
void Visual::RangeCircle(bool* fog, const int size, int centerX, int centerY, int radius) {

	for (int i = centerY - radius; i <= centerY + radius; i++) {
		for (int j = centerX - radius; j <= centerX + radius; j++) {
			if ((pow(j - centerX, 2)) + (pow(i - centerY,2)) <= pow(radius, 2)) {
				fog[i*j] = true;
			}
		}
	}
}