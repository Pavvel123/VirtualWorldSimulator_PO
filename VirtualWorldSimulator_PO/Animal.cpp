#include "Animal.h"
#include "MyFunctions.h"
#include <iostream>
#include <string>
#include "NoMoreSpaceAvailableException.h"

#include "Antelope.h"
#include "Fox.h"
#include "Sheep.h"
#include "Tortoise.h"
#include "Wolf.h"

using std::cout;
using std::endl;
using std::string;

Animal::Animal(World& world) : Organism(world), prevXpos(0), prevYpos(0)
{
	world.SetAnimalsLength(world.GetAnimalsLength() + 1);
}

void Animal::Action()
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
	world.logs += "~>  ";
	world.logs += OrganismName();
	world.logs += " is going ";

	if (direction == N && yPos != 1 || direction == S && yPos == world.GetHeight())
	{
		yPos--;
		world.logs += "north ";
	}
	else if (direction == E && xPos != world.GetWidth() || direction == W && xPos == 1)
	{
		xPos++;
		world.logs += "east ";
	}
	else if (direction == S && yPos != world.GetHeight() || direction == N && yPos == 1)
	{
		yPos++;
		world.logs += "south ";
	}
	else //if (direction == W && xPos != 1 || direction == E && xPos == world.GetWidth())
	{
		xPos--;
		world.logs += "west ";
	}

	world.logs += "to (";
	world.logs += std::to_string(xPos);
	world.logs += ", ";
	world.logs += std::to_string(yPos);
	world.logs += ").\n";
}

void Animal::Collision(Organism* organism)
{
	if (OrganismName() == organism->OrganismName())
	{
		int newPos[2]{ xPos, yPos };
		if (age > 5 && organism->GetAge() > 5)
		{
			try
			{
				NewPosIn8Neighbourhood(newPos);
			}
			catch (const NoMoreSpaceAvailableException&)
			{
			}
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
		try
		{
			NewPosIn8Neighbourhood(newPos);
			xPos = newPos[0];
			yPos = newPos[1];
		}
		catch (const NoMoreSpaceAvailableException& e)
		{
			isDead = true;
		}
	}
}

void Animal::AddToLogDeath()
{
	world.logs += " +  ";
	world.logs += OrganismName();
	world.logs += " from (";
	world.logs += std::to_string(xPos);
	world.logs += ", ";
	world.logs += std::to_string(yPos);
	world.logs += ") has been killed.\n";
}

Animal::~Animal()
{
	world.SetAnimalsLength(world.GetAnimalsLength() - 1);
}