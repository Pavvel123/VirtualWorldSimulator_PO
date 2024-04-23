#include "Antelope.h"
#include "MyFunctions.h"
#include <iostream>
#define GETAWAY_PROBABILITY 50

using std::cout;
using std::endl;

Antelope::Antelope(int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = 4;
	Organism::initiative = 4;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
	Organism::AddToLogBorn();
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
	Organism::AddToLogBorn();
}

void Antelope::Action()
{
	enum Direction
	{
		N,
		E,
		S,
		W,
	};

	SetTextColour(15);
	prevXpos = xPos;
	prevYpos = yPos;
	Direction direction = Direction(rand() % 4);
	world.logs += "~~> Antelope is running ";

	if (direction == N && yPos > 2 || direction == S && yPos >= world.GetHeight() - 1)
	{
		yPos -= 2;
		world.logs += "north ";
	}
	else if (direction == E && xPos < world.GetWidth() - 1 || direction == W && xPos <= 2)
	{
		xPos += 2;
		world.logs += "east ";
	}
	else if (direction == S && yPos < world.GetHeight() - 1 || direction == N && yPos <= 2)
	{
		yPos += 2;
		world.logs += "south ";
	}
	else// if (direction == W && xPos > 2 || direction == E && xPos >= world.GetWidth() - 1)
	{
		xPos -= 2;
		world.logs += "west ";
	}

	world.logs += "to (";
	world.logs += std::to_string(xPos);
	world.logs += ", ";
	world.logs += std::to_string(yPos);
	world.logs += ").\n";
}

void Antelope::Collision(Organism* organism)
{
	Animal::Collision(organism);
	if (!dynamic_cast<Antelope*>(organism))
	{
		if (rand() % 100 < GETAWAY_PROBABILITY)
		{
			isDead = false;
			int newPos[2]{xPos, yPos};
			NewPosIn8Neighbourhood(newPos);
			xPos = newPos[0];
			yPos = newPos[1];
		}
		else
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
}

void Antelope::Print()
{
	Organism::Print();
	SetTextColour(176);
	cout << "AN";
}

const char* Antelope::OrganismName() const
{
	return "Antelope";
}

Antelope::~Antelope()
{
	AddToLogDeath();
}