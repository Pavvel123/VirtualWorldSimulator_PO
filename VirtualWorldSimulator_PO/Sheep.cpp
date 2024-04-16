#include "Sheep.h"
#include "MyFunctions.h"
#include <iostream>

Sheep::Sheep(int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = 4;
	Organism::initiative = 4;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Sheep::Action()
{
	Animal::Action();
}

void Sheep::Collision()
{
}

void Sheep::Print()
{
	Organism::Print();
	SetTextColour(112);//207
	std::cout << "SH";
}

Sheep::~Sheep()
{
}
