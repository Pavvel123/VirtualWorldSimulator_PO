#include "Guarana.h"
#include "MyFunctions.h"
#include <iostream>

using std::cout;

Guarana::Guarana(int xPos, int yPos, World& world)
	: Plant(world)
{
	Organism::strength = 0;
	Organism::initiative = 0;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
	Organism::AddToLogBorn();
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
	Organism::AddToLogBorn();
}

void Guarana::Action()
{
	Plant::Action();
}

void Guarana::Collision(Organism* organism)
{
	organism->SetStrength(organism->GetStrength() + 3);

	world.logs += " ^  Guarana from (";
	world.logs += std::to_string(xPos);
	world.logs += ", ";
	world.logs += std::to_string(yPos);
	world.logs += ") has increased ";
	world.logs += organism->OrganismName();
	world.logs += "'s strength to ";
	world.logs += std::to_string(organism->GetStrength());
	world.logs += ".\n";
}

void Guarana::Print()
{
	Organism::Print();
	SetTextColour(164);
	cout << "GU";
}

const char* Guarana::OrganismName() const
{
	return "Guarana";
}

Guarana::~Guarana()
{
	AddToLogDeath();
}
