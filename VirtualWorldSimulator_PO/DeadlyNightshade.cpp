#include "DeadlyNightshade.h"

DeadlyNightshade::DeadlyNightshade(int strength, int xPos, int yPos, World& world)
	: Plant(world)
{
	Organism::strength = strength;
	Organism::initiative = 0;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void DeadlyNightshade::Action(World& world)
{
}

void DeadlyNightshade::Collision(World& world)
{
}

void DeadlyNightshade::Print()
{
}

DeadlyNightshade::~DeadlyNightshade()
{
}
