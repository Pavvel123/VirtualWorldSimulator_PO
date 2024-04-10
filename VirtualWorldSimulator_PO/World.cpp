#include "World.h"

World::World(unsigned width, unsigned height, vector<Organism*> organisms)
	: width(width), height(height), organisms(organisms)
{
}

World::World(unsigned width, unsigned height)
	: width(width), height(height), organisms(0)
{
}

void World::MakeTurn()
{
}

void World::Print()
{
}

World::~World()
{
}
