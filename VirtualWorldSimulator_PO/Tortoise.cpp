#include "Tortoise.h"
#include "MyFunctions.h"
#include <iostream>
#define MOVE_PROBABILITY 25

using std::cout;

Tortoise::Tortoise(int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = 2;
	Organism::initiative = 1;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
	Organism::AddToLogBorn();
}

Tortoise::Tortoise(World& world)
	: Animal(world)
{
	int pos[2]{};
	world.RandomPos(pos);
	Organism::strength = 2;
	Organism::initiative = 1;
	Organism::xPos = pos[0];
	Organism::yPos = pos[1];
	Organism::world = world;
	Organism::AddToLogBorn();
}

bool Tortoise::IfDefendedTheAttack(Organism* offensive)
{
	if (offensive->GetStrength() < 5)
	{
		return true;
		world.logs += " !  Tortoise from (";
		world.logs += std::to_string(xPos);
		world.logs += ", ";
		world.logs += std::to_string(yPos);
		world.logs += ") has defended the";
		world.logs += offensive->OrganismName();
		world.logs += "'s attack!\n";
	}
	else
	{
		return false;
	}
}

void Tortoise::Action()
{
	if (rand() % 100 < MOVE_PROBABILITY)
	{
		Animal::Action();
	}
	else
	{
		world.logs += " >  Tortoise won't go anywhere.\n";
	}
}

void Tortoise::Collision(Organism* organism)
{
	Animal::Collision(organism);
	if (!dynamic_cast<Tortoise*>(organism))
	{
		if (organism->IfDefendedTheAttack(this))
		{
			xPos = prevXpos;
			yPos = prevYpos;
			isDead = false;
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

void Tortoise::Print()
{
	Organism::Print();
	SetTextColour(223);
	cout << "TT";
}

const char* Tortoise::OrganismName() const
{
	return "Tortoise";
}

Tortoise::~Tortoise()
{
	AddToLogDeath();
}
