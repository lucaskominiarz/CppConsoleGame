#include <iostream>
#include "Visual.h"
#include "Cell.h"
#include "Plane.h"
#include "Drone.h"
#include "BomberPlane.h"
#include "HealerDrone.h"
#include "Building.h"
#include "Debug.h"

constexpr int gridSize = 21;
Cell* grid[gridSize * gridSize]{ nullptr };
Visual visual;
bool win = false;
bool isJ1 = true;

Cell* GetCell(int row, int col) {
    if (row < 0 || row >= gridSize || col < 0 || col >= gridSize) return nullptr;
    return grid[row * gridSize + col];
}

void SetCell(int row, int col, Cell* cell) {
    grid[row * gridSize + col] = cell;
}

void InitUnits() {
    // unites du J1
    SetCell(1, 1, new Plane(true));
    SetCell(5, 1, new Drone(true));
    SetCell(10, 1, new BomberPlane(true));
    SetCell(15, 1, new Drone(true));
    SetCell(19, 1, new HealerDrone(true));

    // unites du J2

    SetCell(1, 19, new Plane(false));
    SetCell(5, 19, new Drone(false));
    SetCell(10, 19, new BomberPlane(false));
    SetCell(15, 19, new Drone(false));
    SetCell(19, 19, new HealerDrone(false));
}
void InitBuildings() {
    // buildings pour avoir un gameplay plus strategiques
    SetCell(10, 10, new Building());
    SetCell(11, 10, new Building());
    SetCell(10, 11, new Building());
    SetCell(11, 11, new Building());
    SetCell(9, 10, new Building());
    SetCell(10, 9, new Building());
    SetCell(9, 9, new Building());
    SetCell(11, 9, new Building());
    SetCell(9, 11, new Building());

    SetCell(5, 5, new Building());
    SetCell(15, 15, new Building());
    SetCell(5, 15, new Building());
    SetCell(15, 5, new Building());
}

int main() {
    
    InitUnits();
    InitBuildings();

    while (!win) {
        visual.Draw(grid, gridSize, isJ1);
        std::cout << "\n--- Tour du Joueur " << (isJ1 ? "1 (Bleu)" : "2 (Rouge)") << " ---\n";
        int srcRow, srcCol;
        std::cout << "Selectionnez une unite (Ligne Colonne): ";
        if (!(std::cin >> srcRow >> srcCol)) break;
        Cell* selected = GetCell(srcRow, srcCol);
        if (!selected || selected->IsEmpty()) {
            std::cout << "Case vide, appuyez sur Entree...\n";
            std::cin.ignore();
            std::cin.get();
            continue;
        }
        if (selected->GetPlayer() != isJ1)
        {
            std::cout << "Cette unite appartient a l'adversaire\n";
#if isDebug 
            std::cout << "Unite selectionnee (Portee: " << selected->GetRange()
                << ", Vitesse: " << selected->GetMoveSpeed() << ")\n";
#endif // isDebug
            std::cout << "Appuyez sur Entree pour continuer...";
            std::cin.ignore();
            std::cin.get();

            continue;
        }
        std::cout << "Unite selectionnee (Portee: " << selected->GetRange()
            << ", Vitesse: " << selected->GetMoveSpeed() << ")\n";
        std::cout << "1. Se deplacer\n2. Attaquer\n0. Annuler\nChoix : ";
        int action;
        std::cin >> action;

        if (action == 1) {
            int destRow, destCol;
            std::cout << "Destination (Ligne Colonne) : ";
            std::cin >> destRow >> destCol;

            Cell* targetCell = GetCell(destRow, destCol);

            if (targetCell != nullptr && !targetCell->IsEmpty()) {
                std::cout << "La case de destination est occupee\n";
            }
            else if (!selected->CanMoveTo(srcRow, srcCol, destRow, destCol)) {
                std::cout << "Destination trop eloignee (Vitesse max : " << selected->GetMoveSpeed() << ")\n";
            }
            else
            {
                SetCell(destRow, destCol, selected);
                SetCell(srcRow, srcCol, nullptr);
                std::cout << "Deplacement reussi\n";
                isJ1 = !isJ1;
            }
        }
        else if (action == 2) {
            int targetRow, targetCol;
            std::cout << "Cible de l'attaque (Ligne Colonne) : ";
            std::cin >> targetRow >> targetCol;

            BomberPlane* bomber = dynamic_cast<BomberPlane*>(selected);

            if (bomber) {
                if (bomber->CanAttack(srcRow, srcCol, targetRow, targetCol)) {
                    bomber->Explode(grid, gridSize, targetRow, targetCol);

                    for (int r = targetRow - 1; r <= targetRow + 1; ++r) {
                        for (int c = targetCol - 1; c <= targetCol + 1; ++c) {
                            Cell* cell = GetCell(r, c);
                            if (cell && cell->GetHp() <= 0) {
                                std::cout << "Unite detruite en (" << r << ", " << c << ")\n";
                                delete cell;
                                SetCell(r, c, nullptr);
                            }
                        }
                    }
                    isJ1 = !isJ1;
                }
                else {
                    std::cout << "Cible hors de portee de tir !\n";
                }
            }
            else {
                Cell* targetCell = GetCell(targetRow, targetCol);
                if (!targetCell || targetCell->IsEmpty()) {
                    std::cout << "Vous n'avez touche personne\n";
                    isJ1 = !isJ1;
                }
                else if (selected->Attack(targetCell, srcRow, srcCol, targetRow, targetCol)) {
                    std::cout << "Attaque reussie\n";
                    if (targetCell->GetHp() <= 0) {
                        std::cout << "Unite ennemie detruite\n";
                        delete targetCell;
                        SetCell(targetRow, targetCol, nullptr);
                    }
                    isJ1 = !isJ1;
                }
                else {
                    std::cout << "Impossible d'attaquer (hors de portee ou cible alliee)\n";
                }
            }
        }
        std::cout << "Appuyez sur Entree pour continuer...";
        std::cin.ignore();
        std::cin.get();
    }

    for (int i = 0; i < gridSize * gridSize; ++i) {
        delete grid[i];
    }

    return 0;
}