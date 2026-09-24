#include "Visual.h"

void Visual::Draw(Cell* grid, const int size) {
	system("cls");
	for (size_t i = 1; i <= size; i++) {

		std::cout << "|";

		for (size_t j = 0; j < size; j++) {

			Cell* ptr = &grid[i*j];
			if (dynamic_cast<Plane*>(ptr)) { // marche pas 
				std::cout << "p|";
			}
			else if (dynamic_cast<Drone*>(ptr)) {
				std::cout << "d|";
			}
			else {
				std::cout << "_|";
			}
		}
		std::cout << std::endl;
	} // me renseigner sur les string stream et faire le rayon de range qui se redraw en fonction du joueur qui joue 
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