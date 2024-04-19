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
	if (age > 5 && organism->GetAge() > 5 && dynamic_cast<Antelope*>(this) && dynamic_cast<Antelope*>(organism))
	{
		world.AddOrganism(new Antelope(xPos + 1, yPos + 1, world));
		xPos--;
		yPos--;
	}
}

void Animal::Print()
{
	//SetTextColour(207);//196
}

Animal::~Animal()
{
	world.SetAnimalsLength(world.GetAnimalsLength() - 1);
}