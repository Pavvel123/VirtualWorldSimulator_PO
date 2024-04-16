#include "Fox.h"
#include "MyFunctions.h"
#include <iostream>

Fox::Fox(int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = 3;
	Organism::initiative = 7;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Fox::Action()
{
	Animal::Action();
}

void Fox::Collision()
{
}

void Fox::Print()
{
	Organism::Print();
	SetTextColour(207);
	std::cout << "FX";
}

Fox::~Fox()
{
}
