#pragma once
#include <vector>
#include <string>
#include "Organism.h"
#include <fstream>

using std::vector;
using std::string;
using std::fstream;

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
	string logs;
	World(int width, int height);
	World(fstream* file);

	void AddOrganism(Organism* organism);

	int GetAnimalsLength() const;
	int GetPlantsLength() const;
	int GetWidth() const;
	int GetHeight() const;
	vector<Organism*>* GetOrganisms() const;
	string GetLogs() const;

	void SetAnimalsLength(int value);
	void SetPlantsLength(int value);
	void AddToLogs(const char* log);
	void ClearLogs();

	bool IsOrganismOnXY(int x, int y);
	int* RandomPos(int* output);
	void SortOrganisms();

	int MakeTurn();
	void Print();

	void SaveToFile(fstream* file);
	~World();

	//friend string operator+=(string str, string text);
};