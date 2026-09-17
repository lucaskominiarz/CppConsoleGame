#pragma once
#include "Cell.h"
class Plane : public Cell
{
public : 
	int GetHp() { return hp; };
	bool TakeDamage(int value);

private:
	int hp;
};

