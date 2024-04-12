#include "Organism.h"
#include "MyFunctions.h"

Organism::Organism(World& world) : strength(0), initiative(0), xPos(0), yPos(0), world(world)
{
}

void Organism::Print()
{
	Gotoxy(2 * xPos - 1, yPos + 2);
}
