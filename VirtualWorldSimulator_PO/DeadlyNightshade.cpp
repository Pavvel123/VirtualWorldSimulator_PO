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

DeadlyNightshade::DeadlyNightshade(World& world)
	: Plant(world)
{
	int pos[2]{};
	world.RandomPos(pos);
	Organism::strength = 99;
	Organism::initiative = 0;
	Organism::xPos = pos[0];
	Organism::yPos = pos[1];
	Organism::world = world;
}

void DeadlyNightshade::Action()
{
	Plant::Action();
}

void DeadlyNightshade::Collision(Organism* organism)
{
}

void DeadlyNightshade::Print()
{
	Organism::Print();
	SetTextColour(160);
	std::cout << "DN";
}

const char* DeadlyNightshade::OrganismName() const
{
	return "DeadlyNightshade";
}

DeadlyNightshade::~DeadlyNightshade()
{
	//Plant::~Plant();
}