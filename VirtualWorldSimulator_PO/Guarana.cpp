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

Guarana::Guarana(World& world)
	: Plant(world)
{
	int pos[2]{};
	world.RandomPos(pos);
	Organism::strength = 0;
	Organism::initiative = 0;
	Organism::xPos = pos[0];
	Organism::yPos = pos[1];
	Organism::world = world;
}

void Guarana::Action()
{
	Plant::Action();
}

void Guarana::Collision(Organism* organism)
{
	organism->SetStrength(organism->GetStrength() + 3);
}

void Guarana::Print()
{
	Organism::Print();
	SetTextColour(164);
	std::cout << "GU";
	//std::cout << (char)177 << (char)177;
}

const char* Guarana::OrganismName() const
{
	return "Guarana";
}

Guarana::~Guarana()
{
	//Plant::~Plant();
}
