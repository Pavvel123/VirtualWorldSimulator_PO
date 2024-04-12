#include "Guarana.h"
#include "MyFunctions.h"
#include <iostream>

Guarana::Guarana(int xPos, int yPos, World& world)
	: Plant(world)
{
	Organism::strength = 0;
	Organism::initiative = 0;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Guarana::Action(World& world)
{
}

void Guarana::Collision(World& world)
{
}

void Guarana::Print()
{
	Organism::Print();
	SetTextColour(164);
	std::cout << "GU";
	//std::cout << (char)177 << (char)177;
}

Guarana::~Guarana()
{
}
