#include "Fox.h"

Fox::Fox(int strength, int initiative, int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = strength;
	Organism::initiative = initiative;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Fox::Action(World& world)
{
}

void Fox::Collision(World& world)
{
}

void Fox::Print()
{
}

Fox::~Fox()
{
}
