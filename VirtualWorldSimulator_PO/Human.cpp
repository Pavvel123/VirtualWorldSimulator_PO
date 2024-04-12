#include "Human.h"
#include <iostream>
#include "MyFunctions.h"

Human::Human(int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = 5;
	Organism::initiative = 4;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Human::Action(World& world)
{
}

void Human::Collision(World& world)
{
}

void Human::Print()
{
	Organism::Print();
	SetTextColour(148);//159
	std::cout << "HU";
}

Human::~Human()
{
}
