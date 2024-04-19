#include "Fox.h"
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

Fox::Fox(int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = 3;
	Organism::initiative = 7;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
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
}

void Fox::Action()
{
	SetTextColour(15);//127

	cout << "Fox is going ";
	int newX = xPos;
	int newY = yPos;

	while (newX == xPos && newY == yPos)
	{
		Direction direction = Direction(rand() % 4);
		switch (direction)
		{
		case N:
			if (yPos == 1)
			{
				if (CanMove(xPos, yPos + 1))
				{
					newY++;
					cout << "south ";
				}
			}
			else
			{
				if (CanMove(xPos, yPos - 1))
				{
					newY--;
					cout << "north ";
				}
			}
			break;
		case E:
			if (xPos == world.GetWidth())
			{
				if (CanMove(xPos - 1, yPos))
				{
					newX--;
					cout << "west ";
				}
			}
			else
			{
				if (CanMove(xPos + 1, yPos))
				{
					newX++;
					cout << "east ";
				}
			}
			break;
		case S:
			if (yPos == world.GetHeight())
			{
				if (CanMove(xPos, yPos - 1))
				{
					newY--;
					cout << "north ";
				}
			}
			else
			{
				if (CanMove(xPos, yPos + 1))
				{
					newY++;
					cout << "south ";
				}
			}
			break;
		case W:
			if (xPos == 1)
			{
				if (CanMove(xPos + 1, yPos))
				{
					newX++;
					cout << "east ";
				}
			}
			else
			{
				if (CanMove(xPos - 1, yPos))
				{
					newX--;
					cout << "west ";
				}
			}
			break;
		}
	}
	xPos = newX;
	yPos = newY;
	cout << "to (" << xPos << ", " << yPos << ").";
}

void Fox::Collision(Organism* organism)
{
	Animal::Collision(organism);
	if (!dynamic_cast<Fox*>(organism))
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
	//Animal::~Animal();
}
