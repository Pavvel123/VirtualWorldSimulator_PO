#include "Sonchus.h"

Sonchus::Sonchus(int strength, int xPos, int yPos, World& world)
	: Plant(world)
{
	Organism::strength = strength;
	Organism::initiative = 0;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Sonchus::Action(World& world)
{
}

void Sonchus::Collision(World& world)
{
}

void Sonchus::Print()
{
}

Sonchus::~Sonchus()
{
}
