#include <iostream>
#include "Visual.h"
#include "Cell.h"
#include "Plane.h"
#include "Drone.h"

#define isDebug 0 // modifier pour activer/ desactiver le debug

constexpr int gridSize = 20;
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

int main() { // gameplay loop principale
    SetCell(5, 7, new Plane(true));
    SetCell(6, 8, new Drone(false));

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
#if isDebug // Choisir mode debug
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
            Cell* targetCell = GetCell(targetRow, targetCol);
            if (!targetCell || targetCell->IsEmpty()) {
                std::cout << "Aucune cible sur cette case\n";
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
        std::cout << "Appuyez sur Entree pour continuer...";
        std::cin.ignore();
        std::cin.get();
    }
    for (int i = 0; i < gridSize * gridSize; ++i) {
        delete grid[i];
    }

    return 0;
}