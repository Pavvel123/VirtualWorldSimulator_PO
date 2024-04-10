#include "Tortoise.h"

Tortoise::Tortoise(int strength, int initiative, int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = strength;
	Organism::initiative = initiative;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Tortoise::Action(World& world)
{
}

void Tortoise::Collision(World& world)
{
}

void Tortoise::Print()
{
}

Tortoise::~Tortoise()
{
}
