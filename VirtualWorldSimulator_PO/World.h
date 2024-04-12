#pragma once
#include <vector>
#include "Organism.h"

using std::vector;

class Organism;

class World
{
private:
	vector<Organism*>* organisms;
	unsigned width;
	unsigned height;

public:
	World(unsigned width, unsigned height, vector<Organism*>* organisms);
	//World(unsigned width, unsigned height);
	void AddOrganism(Organism* organism);
	unsigned GetWidth() const;
	unsigned GetHeight() const;
	void MakeTurn();
	void Print();
	~World();
};