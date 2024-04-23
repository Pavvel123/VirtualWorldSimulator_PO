#include "Wolf.h"
#include <iostream>
#include "MyFunctions.h"

using std::cout;

Wolf::Wolf(int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = 9;
	Organism::initiative = 5;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
	Organism::AddToLogBorn();
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
	Organism::AddToLogBorn();
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
		if (organism->IfDefendedTheAttack(this))
		{
			xPos = prevXpos;
			yPos = prevYpos;
		}
		else
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
}

void Wolf::Print()
{
	Organism::Print();
	SetTextColour(143);
	cout << "WF";
}

const char* Wolf::OrganismName() const
{
	return "Wolf";
}

Wolf::~Wolf()
{
	AddToLogDeath();
}
