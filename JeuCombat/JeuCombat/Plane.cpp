#include "Plane.h"
bool Plane::TakeDamage(int value) {
	hp -= value;
	return hp <= 0;
}

// Attaque et peut être un appel a la fonction visual pour demander a afficher ses stats 
