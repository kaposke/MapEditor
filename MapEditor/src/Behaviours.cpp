#include "Behaviours.h"

void Behaviours::addBehaviour(int r, int g, int b)
{
	Type behaviour;
	behaviour.r = r;
	behaviour.g = g;
	behaviour.b = b;
	behaviours.push_back(behaviour);
}
