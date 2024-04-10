#include "Sheep.h"

Sheep::Sheep(int strength, int initiative, int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = strength;
	Organism::initiative = initiative;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Sheep::Action(World& world)
{
}

void Sheep::Collision(World& world)
{
}

void Sheep::Print()
{
}

Sheep::~Sheep()
{
}
