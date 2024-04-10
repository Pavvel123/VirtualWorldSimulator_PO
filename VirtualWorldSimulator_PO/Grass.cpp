#include "Grass.h"

Grass::Grass(int strength, int xPos, int yPos, World& world)
	: Plant(world)
{
	Organism::strength = strength;
	Organism::initiative = 0;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Grass::Action(World& world)
{
}

void Grass::Collision(World& world)
{
}

void Grass::Print()
{
}

Grass::~Grass()
{
}
