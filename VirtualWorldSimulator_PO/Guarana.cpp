#include "Guarana.h"

Guarana::Guarana(int strength, int xPos, int yPos, World& world)
	: Plant(world)
{
	Organism::strength = strength;
	Organism::initiative = 0;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Guarana::Action(World& world)
{
}

void Guarana::Collision(World& world)
{
}

void Guarana::Print()
{
}

Guarana::~Guarana()
{
}
