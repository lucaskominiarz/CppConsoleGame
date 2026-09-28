#include "Visual.h"
#include "Plane.h"
#include "Drone.h"
#include <iostream>
#include <sstream>
#include <windows.h>

void SetColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}

void Visual::Draw(Cell* grid[], const int size, bool isJ1Turn) {
    system("cls");

    bool* range = new bool[size * size] { false };
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            Cell* ptr = grid[i * size + j];
            if (ptr != nullptr && !ptr->IsEmpty() && ptr->GetPlayer() == isJ1Turn) {
                RangeCircle(range, size, j, i, ptr->GetRange());
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        SetColor(7);
        std::cout << "|";

        for (int j = 0; j < size; ++j) {
            Cell* ptr = grid[i * size + j];
            bool inRange = range[i * size + j];

            if (dynamic_cast<Plane*>(ptr)) {
                SetColor(ptr->GetPlayer() ? 9 : 12);
                std::cout << "p";
            }
            else if (dynamic_cast<Drone*>(ptr)) {
                SetColor(ptr->GetPlayer() ? 9 : 12);
                std::cout << "d";
            }
            else {
                if (inRange) {
                    SetColor(10);
                    std::cout << ".";
                }
                else {
                    SetColor(7);
                    std::cout << "_";
                }
            }
            SetColor(7);
            std::cout << "|";
        }
        std::cout << "\n";
    }

    delete[] range;
}

void Visual::RangeCircle(bool* range, const int size, int centerX, int centerY, int radius) {
    int minY = (centerY - radius < 0) ? 0 : centerY - radius;
    int maxY = (centerY + radius >= size) ? size - 1 : centerY + radius;
    int minX = (centerX - radius < 0) ? 0 : centerX - radius;
    int maxX = (centerX + radius >= size) ? size - 1 : centerX + radius;

    for (int i = minY; i <= maxY; ++i) {
        int dy = i - centerY;
        for (int j = minX; j <= maxX; ++j) {
            int dx = j - centerX;
            if (dx * dx + dy * dy <= radius * radius) {
                range[i * size + j] = true;
            }
        }
    }
}