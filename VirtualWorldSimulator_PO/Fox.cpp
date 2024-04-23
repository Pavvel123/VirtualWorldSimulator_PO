#include "Fox.h"
#include "MyFunctions.h"
#include <iostream>
#include "NoMoreSpaceAvailableException.h"

using std::cout;
using std::endl;

Fox::Fox(int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = 3;
	Organism::initiative = 7;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
	Organism::AddToLogBorn();
}

Fox::Fox(World& world)
	: Animal(world)
{
	int pos[2]{};
	world.RandomPos(pos);
	Organism::strength = 3;
	Organism::initiative = 7;
	Organism::xPos = pos[0];
	Organism::yPos = pos[1];
	Organism::world = world;
	Organism::AddToLogBorn();
}

void Fox::Action()
{
	enum Direction
	{
		N,
		E,
		S,
		W,
	};

	SetTextColour(15);//127
	int newX = xPos;
	int newY = yPos;

	bool possibleN = true;
	bool possibleE = true;
	bool possibleS = true;
	bool possibleW = true;

	while (newX == xPos && newY == yPos)
	{
		Direction direction = Direction(rand() % 4);
		if (direction == N && yPos != 1 || direction == S && yPos == world.GetHeight())
		{
			if (direction == S)
			{
				possibleS = false;
			}
			if (possibleN && CanMove(xPos, yPos - 1))
			{
				newY--;
				world.logs += "~>  Fox is going north to (";
			}
			else if (possibleN)
			{
				possibleN = false;
				world.logs += " !  There is organism on north (";
				world.logs += std::to_string(xPos);
				world.logs += ", ";
				world.logs += std::to_string(yPos - 1);
				world.logs += ") stronger than Fox. Won't go there.\n";
			}
		}
		else if (direction == E && xPos != world.GetWidth() || direction == W && xPos == 1)
		{
			if (direction == W)
			{
				possibleW = false;
			}
			if (possibleE && CanMove(xPos + 1, yPos))
			{
				newX++;
				world.logs += "~>  Fox is going east to (";
			}
			else if (possibleE)
			{
				possibleE = false;
				world.logs += " !  There is organism on east (";
				world.logs += std::to_string(xPos + 1);
				world.logs += ", ";
				world.logs += std::to_string(yPos);
				world.logs += ") stronger than Fox. Won't go there.\n";
			}
		}
		else if (direction == S && yPos != world.GetHeight() || direction == N && yPos == 1)
		{
			if (direction == N)
			{
				possibleN = false;
			}
			if (possibleS && CanMove(xPos, yPos + 1))
			{
				newY++;
				world.logs += "~>  Fox is going south to (";
			}
			else if (possibleS)
			{
				possibleS = false;
				world.logs += " !  There is organism on south (";
				world.logs += std::to_string(xPos);
				world.logs += ", ";
				world.logs += std::to_string(yPos + 1);
				world.logs += ") stronger than Fox. Won't go there.\n";
			}
		}
		else// if (direction == W && xPos != 1 || direction == E && xPos == world.GetWidth())
		{
			if (direction == E)
			{
				possibleE = false;
			}
			if (possibleW && CanMove(xPos - 1, yPos))
			{
				newX--;
				world.logs += "~>  Fox is going west to (";
			}
			else if (possibleW)
			{
				possibleW = false;
				world.logs += " !  There is organism on west (";
				world.logs += std::to_string(xPos - 1);
				world.logs += ", ";
				world.logs += std::to_string(yPos);
				world.logs += ") stronger than Fox. Won't go there.\n";
			}
		}

		if (!(possibleN || possibleE || possibleS || possibleW))
		{
			world.logs += "!!  No more space for Fox on (";
			world.logs += std::to_string(xPos);
			world.logs += ", ";
			world.logs += std::to_string(yPos);
			world.logs += ")!\n";
			throw NoMoreSpaceAvailableException();
		}
	}
	prevXpos = xPos;
	prevYpos = yPos;
	xPos = newX;
	yPos = newY;
	world.logs += std::to_string(xPos);
	world.logs += ", ";
	world.logs += std::to_string(yPos);
	world.logs += ").\n";
}

void Fox::Collision(Organism* organism)
{
	Animal::Collision(organism);
	if (!dynamic_cast<Fox*>(organism))
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

void Fox::Print()
{
	Organism::Print();
	SetTextColour(207);
	cout << "FX";
}

bool Fox::CanMove(int newX, int newY)
{
	for (Organism* organism : *world.GetOrganisms())
	{
		if (organism->GetXPos() == newX && organism->GetYPos() == newY && organism->GetStrength() > strength)
		{
			return false;
		}
	}
	return true;
}

const char* Fox::OrganismName() const
{
	return "Fox";
}

Fox::~Fox()
{
	AddToLogDeath();
}
