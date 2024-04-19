#include "Tortoise.h"
#include "MyFunctions.h"
#include <iostream>
#define MOVE_PROBABILITY 25

Tortoise::Tortoise(int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = 2;
	Organism::initiative = 1;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
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
}

void Tortoise::Action()
{
	bool willMove = rand() % 100 + 1 < MOVE_PROBABILITY;
	if (willMove)
	{
		Animal::Action();
	}
}

void Tortoise::Collision(Organism* organism)
{
	Animal::Collision(organism);
	if (!dynamic_cast<Tortoise*>(organism))
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

void Tortoise::Print()
{
	Organism::Print();
	SetTextColour(223);//203
	std::cout << "TT";
}

const char* Tortoise::OrganismName() const
{
	return "Tortoise";
}

Tortoise::~Tortoise()
{
	//Animal::~Animal();
}
