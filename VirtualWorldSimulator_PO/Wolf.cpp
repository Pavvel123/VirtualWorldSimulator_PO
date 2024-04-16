#include "Wolf.h"
#include <iostream>
#include "MyFunctions.h"

Wolf::Wolf(int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = 9;
	Organism::initiative = 5;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Wolf::Action()
{
	Animal::Action();
}

void Wolf::Collision()
{
}

void Wolf::Print()
{
	Organism::Print();
	SetTextColour(143);
	std::cout << "WF";
}

Wolf::~Wolf()
{
}
