#include "SosnowskysHogweed.h"

SosnowskysHogweed::SosnowskysHogweed(int strength, int xPos, int yPos, World& world)
	: Plant(world)
{
	Organism::strength = strength;
	Organism::initiative = 0;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void SosnowskysHogweed::Action(World& world)
{
}

void SosnowskysHogweed::Collision(World& world)
{
}

void SosnowskysHogweed::Print()
{
}

SosnowskysHogweed::~SosnowskysHogweed()
{
}