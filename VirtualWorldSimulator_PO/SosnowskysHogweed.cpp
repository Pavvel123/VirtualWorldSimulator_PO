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

void SosnowskysHogweed::Action()
{
	Plant::Action();
}

void SosnowskysHogweed::Collision()
{
}

void SosnowskysHogweed::Print()
{
	Organism::Print();
	SetTextColour(161);
	std::cout << "SH";
}

SosnowskysHogweed::~SosnowskysHogweed()
{
}