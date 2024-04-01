#pragma once
#include <list>
#include "Organism.h"
class World
{
private:
	std::list<Organism> organisms;

public:
	World();
	void makeTurn();
	void print();
	~World();
};