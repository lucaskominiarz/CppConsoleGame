#include "Plane.h"
bool Plane::TakeDamage(int value) {
	hp -= value;
	return hp <= 0;
}
