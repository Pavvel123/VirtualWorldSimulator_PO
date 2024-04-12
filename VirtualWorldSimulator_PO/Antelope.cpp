#include "Antelope.h"
#include "MyFunctions.h"
#include <iostream>

Antelope::Antelope(int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = 4;
	Organism::initiative = 4;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Antelope::Action(World& world)
{
}

void Antelope::Collision(World& world)
{
}

void Antelope::Print()
{
	Organism::Print();
	SetTextColour(176);
	std::cout << "AN";
}

Antelope::~Antelope()
{
}
