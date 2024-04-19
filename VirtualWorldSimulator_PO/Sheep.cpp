#include "Sheep.h"
#include "MyFunctions.h"
#include <iostream>

Sheep::Sheep(int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = 4;
	Organism::initiative = 4;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

Sheep::Sheep(World& world)
	: Animal(world)
{
	int pos[2]{};
	world.RandomPos(pos);
	Organism::strength = 4;
	Organism::initiative = 4;
	Organism::xPos = pos[0];
	Organism::yPos = pos[1];
	Organism::world = world;
}

void Sheep::Action()
{
	Animal::Action();
}

void Sheep::Collision(Organism* organism)
{
	Animal::Collision(organism);
	if (!dynamic_cast<Sheep*>(organism))
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

void Sheep::Print()
{
	Organism::Print();
	SetTextColour(112);//207
	std::cout << "SH";
}

const char* Sheep::OrganismName() const
{
	return "Sheep";
}

Sheep::~Sheep()
{
	//Animal::~Animal();
}
