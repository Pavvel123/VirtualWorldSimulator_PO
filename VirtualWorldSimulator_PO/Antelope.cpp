#include "Antelope.h"

Antelope::Antelope(int strength, int initiative, int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = strength;
	Organism::initiative = initiative;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Antelope::Action(World& world)
{
}

void Antelope::Collision(World& world)
{
}

void Antelope::Print()
{
}

Antelope::~Antelope()
{
}
