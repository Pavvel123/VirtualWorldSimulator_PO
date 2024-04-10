#include "Wolf.h"

Wolf::Wolf(int strength, int initiative, int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = strength;
	Organism::initiative = initiative;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Wolf::Action(World& world)
{
}

void Wolf::Collision(World& world)
{
}

void Wolf::Print()
{
}

Wolf::~Wolf()
{
}
