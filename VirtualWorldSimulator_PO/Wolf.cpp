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

Wolf::Wolf(World& world)
	: Animal(world)
{
	int pos[2]{};
	world.RandomPos(pos);
	Organism::strength = 9;
	Organism::initiative = 5;
	Organism::xPos = pos[0];
	Organism::yPos = pos[1];
	Organism::world = world;
}

void Wolf::Action()
{
	Animal::Action();
}

void Wolf::Collision(Organism* organism)
{
	Animal::Collision(organism);
	if (!dynamic_cast<Wolf*>(organism))
	{
		if (strength > organism->GetStrength())
		{
			organism->SetIsDead(true);
		}
		else
		{
			isDead = true;
		}
	}
}

void Wolf::Print()
{
	Organism::Print();
	SetTextColour(143);
	std::cout << "WF";
}

const char* Wolf::OrganismName() const
{
	return "Wolf";
}

Wolf::~Wolf()
{
	//Animal::~Animal();
}
