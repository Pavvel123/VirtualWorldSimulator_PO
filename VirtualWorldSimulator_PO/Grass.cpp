#include "Grass.h"
#include "MyFunctions.h"
#include <iostream>

Grass::Grass(int xPos, int yPos, World& world)
	: Plant(world)
{
	Organism::strength = 0;
	Organism::initiative = 0;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Grass::Action(World& world)
{
}

void Grass::Collision(World& world)
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
