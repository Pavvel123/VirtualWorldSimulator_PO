#include "Tortoise.h"
#include "MyFunctions.h"
#include <iostream>

Tortoise::Tortoise(int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = 2;
	Organism::initiative = 1;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Tortoise::Action()
{
	Animal::Action();
}

void Tortoise::Collision()
{
}

void Tortoise::Print()
{
	Organism::Print();
	SetTextColour(223);//203
	std::cout << "TT";
}

Tortoise::~Tortoise()
{
}
