#include "Guarana.h"
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

Guarana::Guarana(int xPos, int yPos, World& world)
	: Plant(world)
{
	Organism::strength = 0;
	Organism::initiative = 0;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Guarana::Action()
{
	Plant::Action();
}

void Guarana::Collision()
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
