#include "Sonchus.h"
#include "MyFunctions.h"
#include <iostream>

using std::cout;

Sonchus::Sonchus(int xPos, int yPos, World& world)
	: Plant(world)
{
	Organism::strength = 0;
	Organism::initiative = 0;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
	Organism::AddToLogBorn();
}

Sonchus::Sonchus(World& world)
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

void Sonchus::Action()
{
	for (int i = 0; i < 3; i++)
	{
		Plant::Action();
	}
}

void Sonchus::Collision(Organism* organism)
{
}

void Sonchus::Print()
{
	Organism::Print();
	SetTextColour(174);
	cout << "SN";
}

const char* Sonchus::OrganismName() const
{
	return "Sonchus";
}

Sonchus::~Sonchus()
{
	AddToLogDeath();
}
