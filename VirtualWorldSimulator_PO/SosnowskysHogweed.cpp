#include "SosnowskysHogweed.h"
#include "MyFunctions.h"
#include <iostream>

SosnowskysHogweed::SosnowskysHogweed(int xPos, int yPos, World& world)
	: Plant(world)
{
	Organism::strength = 10;
	Organism::initiative = 0;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

SosnowskysHogweed::SosnowskysHogweed(World& world)
	: Plant(world)
{
	int pos[2]{};
	world.RandomPos(pos);
	Organism::strength = 10;
	Organism::initiative = 0;
	Organism::xPos = pos[0];
	Organism::yPos = pos[1];
	Organism::world = world;
}

void SosnowskysHogweed::Action()
{
	Plant::Action();
}

void SosnowskysHogweed::Collision(Organism* organism)
{
}

void SosnowskysHogweed::Print()
{
	Organism::Print();
	SetTextColour(161);
	std::cout << "SH";
}

const char* SosnowskysHogweed::OrganismName() const
{
	return "SosnowskysHogweed";
}

SosnowskysHogweed::~SosnowskysHogweed()
{
	//Plant::~Plant();
}