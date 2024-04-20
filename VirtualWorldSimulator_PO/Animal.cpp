#include "Animal.h"
#include "MyFunctions.h"
#include <iostream>

#include "Antelope.h"
#include "Fox.h"
#include "Sheep.h"
#include "Tortoise.h"
#include "Wolf.h"

using std::cout;
using std::endl;

enum Direction
{
	N,
	E,
	S,
	W,
};

Animal::Animal(World& world) : Organism(world)
{
	world.SetAnimalsLength(world.GetAnimalsLength() + 1);
}

void Animal::Action()
{
	SetTextColour(15);//127

	Direction direction = Direction(rand() % 4);
	//cout << OrganismName() << " is going ";
	switch (direction)
	{
	case N:
		if (yPos == 1)
		{
			yPos++;
			//cout << "south ";
		}
		else
		{
			yPos--;
			//cout << "north ";
		}
		break;
	case E:
		if (xPos == world.GetWidth())
		{
			xPos--;
			//cout << "west ";
		}
		else
		{
			xPos++;
			//cout << "east ";
		}
		break;
	case S:
		if (yPos == world.GetHeight())
		{
			yPos--;
			//cout << "north ";
		}
		else
		{
			yPos++;
			//cout << "south ";
		}
		break;
	case W:
		if (xPos == 1)
		{
			xPos++;
			//cout << "east ";
		}
		else
		{
			xPos--;
			//cout << "west ";
		}
		break;
	}
	//cout << "to (" << xPos << ", " << yPos << ").";
}

void Animal::Collision(Organism* organism)
{
	if (OrganismName() == organism->OrganismName())
	{
		int newPos[2]{ xPos, yPos };
		if (age > 5 && organism->GetAge() > 5)
		{
			NewPosIn8Neighbourhood(newPos);
			if (dynamic_cast<Antelope*>(organism))
			{
				Antelope* newAntelope = new Antelope(newPos[0], newPos[1], world);
				world.AddOrganism(newAntelope);
				newAntelope->Print();
			}
			else if (dynamic_cast<Fox*>(organism))
			{
				Fox* newFox = new Fox(newPos[0], newPos[1], world);
				world.AddOrganism(newFox);
				newFox->Print();
			}
			else if (dynamic_cast<Sheep*>(organism))
			{
				Sheep* newSheep = new Sheep(newPos[0], newPos[1], world);
				world.AddOrganism(newSheep);
				newSheep->Print();
			}
			else if (dynamic_cast<Tortoise*>(organism))
			{
				Tortoise* newTortoise = new Tortoise(newPos[0], newPos[1], world);
				world.AddOrganism(newTortoise);
				newTortoise->Print();
			}
			else if (dynamic_cast<Wolf*>(organism))
			{
				Wolf* newWolf = new Wolf(newPos[0], newPos[1], world);
				world.AddOrganism(newWolf);
				newWolf->Print();
			}
		}
		newPos[0] = xPos;
		newPos[1] = yPos;
		NewPosIn8Neighbourhood(newPos);
		xPos = newPos[0];
		yPos = newPos[1];
	}
}
/*
void Animal::Print()
{
}*/

Animal::~Animal()
{
	world.SetAnimalsLength(world.GetAnimalsLength() - 1);
}