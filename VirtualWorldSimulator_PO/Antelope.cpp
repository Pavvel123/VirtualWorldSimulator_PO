#include "Antelope.h"
#include "MyFunctions.h"
#include <iostream>

using std::cout;
using std::endl;

enum Direction
{
	N,
	E,
	S,
	W,
};

Antelope::Antelope(int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = 4;
	Organism::initiative = 4;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

Antelope::Antelope(World& world)
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

void Antelope::Action()
{
	SetTextColour(15);//127

	Direction direction = Direction(rand() % 4);
	cout << OrganismName() << " is going ";
	switch (direction)
	{
	case N:
		if (yPos <= 2)
		{
			yPos += 2;
			cout << "south ";
		}
		else
		{
			yPos -= 2;
			cout << "nort ";
		}
		break;
	case E:
		if (xPos >= world.GetWidth() - 1)
		{
			xPos -= 2;
			cout << "west ";
		}
		else
		{
			xPos += 2;
			cout << "east ";
		}
		break;
	case S:
		if (yPos >= world.GetHeight() - 1)
		{
			yPos -= 2;
			cout << "north ";
		}
		else
		{
			yPos += 2;
			cout << "south ";
		}
		break;
	case W:
		if (xPos <= 2)
		{
			xPos += 2;
			cout << "east ";
		}
		else
		{
			xPos -= 2;
			cout << "west ";
		}
		break;
	}
	cout << "to (" << xPos << ", " << yPos << ").";
}

void Antelope::Collision(Organism* organism)
{
	Animal::Collision(organism);
	if (!dynamic_cast<Antelope*>(organism))
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

void Antelope::Print()
{
	Organism::Print();
	SetTextColour(176);
	std::cout << "AN";
}

const char* Antelope::OrganismName() const
{
	return "Antelope";
}

Antelope::~Antelope()
{
	//Animal::~Animal();
}
