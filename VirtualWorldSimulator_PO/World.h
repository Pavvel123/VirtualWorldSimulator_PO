#pragma once
#include <vector>
#include "Organism.h"

using std::vector;

class Organism;

class World
{
private:
	vector<Organism*>* organisms;
	int animalsLength;
	int plantsLength;
	int width;
	int height;

public:
	World(int width, int height, vector<Organism*>* organisms);
	//World(int width, int height);

	void AddOrganism(Organism* organism);
	void DeleteOrganism(Organism* organism);

	int GetAnimalsLength() const;
	int GetPlantsLength() const;
	int GetWidth() const;
	int GetHeight() const;
	vector<Organism*>* GetOrganisms() const;

	void SetAnimalsLength(int value);
	void SetPlantsLength(int value);

	bool IsOrganismOnXY(int x, int y);
	int* RandomPos(int* output);
	void SortOrganisms();

	void MakeTurn();
	void Print();
	~World();
};