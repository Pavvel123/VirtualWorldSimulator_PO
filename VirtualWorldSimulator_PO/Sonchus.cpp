#include "Sonchus.h"
#include "MyFunctions.h"
#include <iostream>

Sonchus::Sonchus(int xPos, int yPos, World& world)
	: Plant(world)
{
	Organism::strength = 0;
	Organism::initiative = 0;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Sonchus::Action()
{
}

void Sonchus::Collision()
{
}

void Sonchus::Print()
{
	Organism::Print();
	SetTextColour(174);
	std::cout << "SN";
}

Sonchus::~Sonchus()
{
}
