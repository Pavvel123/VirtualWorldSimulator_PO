#include "Grass.h"
#include "MyFunctions.h"
#include <iostream>
#define SEEDING_PROBABILITY 50

enum Direction
{
	N,
	NE,
	E,
	SE,
	S,
	SW,
	W,
	NW
};

Grass::Grass(int xPos, int yPos, World& world)
	: Plant(world)
{
	Organism::strength = 0;
	Organism::initiative = 0;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Grass::Action()
{
	Plant::Action();
}

void Grass::Collision()
{
}

void Grass::Print()
{
	Organism::Print();
	SetTextColour(160);//10
	std::cout << (char)177 << (char)177;
}

Grass::~Grass()
{
}
