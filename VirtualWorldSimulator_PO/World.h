#pragma once
#include <vector>
#include "Organism.h"

using std::vector;

class Organism;

class World
{
private:
	vector<Organism*> organisms;
	int width;
	int height;

public:
	World(unsigned width, unsigned height, vector<Organism*> organisms);
	World(unsigned width, unsigned height);
	void MakeTurn();
	void Print();
	~World();
};