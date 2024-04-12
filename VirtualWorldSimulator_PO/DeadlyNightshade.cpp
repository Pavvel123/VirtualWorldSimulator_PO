#include "DeadlyNightshade.h"
#include "MyFunctions.h"
#include <iostream>

DeadlyNightshade::DeadlyNightshade(int xPos, int yPos, World& world)
	: Plant(world)
{
	Organism::strength = 99;
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
	Organism::Print();
	SetTextColour(160);
	std::cout << "DN";
}

DeadlyNightshade::~DeadlyNightshade()
{
}
