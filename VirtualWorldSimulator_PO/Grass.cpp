#include "Grass.h"
#include "MyFunctions.h"
#include <iostream>

using std::cout;

Grass::Grass(int xPos, int yPos, World& world)
	: Plant(world)
{
	Organism::strength = 0;
	Organism::initiative = 0;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
	Organism::AddToLogBorn();
}

Grass::Grass(World& world)
	: Plant(world)
{
	int pos[2]{};
	world.RandomPos(pos);
	Organism::strength = 0;
	Organism::initiative = 0;
	Organism::xPos = pos[0];
	Organism::yPos = pos[1];
	Organism::world = world;
	Organism::AddToLogBorn();
}

void Grass::Action()
{
	Plant::Action();
}

void Grass::Collision(Organism* organism)
{
}

void Grass::Print()
{
	Organism::Print();
	SetTextColour(160);//10
	cout << (char)177 << (char)177;
}

const char* Grass::OrganismName() const
{
	return "Grass";
}

Grass::~Grass()
{
	AddToLogDeath();
}
