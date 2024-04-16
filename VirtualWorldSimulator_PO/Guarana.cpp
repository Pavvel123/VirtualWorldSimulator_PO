#include "Guarana.h"
#include "MyFunctions.h"
#include <iostream>
#define SEEDING_PROBABILITY 50

enum Direction
{
	N,
	NE,
	E,
	SE,
	S,
	SW,
	W,
	NW
};

Guarana::Guarana(int xPos, int yPos, World& world)
	: Plant(world)
{
	Organism::strength = 0;
	Organism::initiative = 0;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Guarana::Action()
{
	bool willSeed = rand() % 100 + 1 < SEEDING_PROBABILITY;
	if (willSeed)
	{
		Direction direction = Direction(rand() % 8);
		switch (direction)
		{
		case N:
			if (yPos > 1 && !world.IsOrganismOnXY(xPos, yPos - 1))
			{
				world.AddOrganism(new Guarana(xPos, yPos - 1, world));
			}
			break;
		case NE:
			if (xPos < world.GetWidth() && yPos > 1 && !world.IsOrganismOnXY(xPos + 1, yPos - 1))
			{
				world.AddOrganism(new Guarana(xPos + 1, yPos - 1, world));
			}
			break;
		case E:
			if (xPos < world.GetWidth() && !world.IsOrganismOnXY(xPos + 1, yPos))
			{
				world.AddOrganism(new Guarana(xPos + 1, yPos, world));
			}
			break;
		case SE:
			if (xPos < world.GetWidth() && yPos < world.GetHeight() && !world.IsOrganismOnXY(xPos + 1, yPos + 1))
			{
				world.AddOrganism(new Guarana(xPos + 1, yPos + 1, world));
			}
			break;
		case S:
			if (yPos < world.GetHeight() && !world.IsOrganismOnXY(xPos, yPos + 1))
			{
				world.AddOrganism(new Guarana(xPos, yPos + 1, world));
			}
			break;
		case SW:
			if (yPos < world.GetHeight() && xPos > 1 && !world.IsOrganismOnXY(xPos - 1, yPos + 1))
			{
				world.AddOrganism(new Guarana(xPos - 1, yPos + 1, world));
			}
			break;
		case W:
			if (xPos > 1 && !world.IsOrganismOnXY(xPos - 1, yPos))
			{
				world.AddOrganism(new Guarana(xPos - 1, yPos, world));
			}
			break;
		case NW:
			if (xPos > 1 && yPos > 1 && !world.IsOrganismOnXY(xPos - 1, yPos - 1))
			{
				world.AddOrganism(new Guarana(xPos - 1, yPos - 1, world));
			}
			break;
		default:
			break;
		}
	}
}

void Guarana::Collision()
{
}

void Guarana::Print()
{
	Organism::Print();
	SetTextColour(164);
	std::cout << "GU";
	//std::cout << (char)177 << (char)177;
}

Guarana::~Guarana()
{
}
