#include "Plant.h"
#include "DeadlyNightshade.h"
#include "Grass.h"
#include "Guarana.h"
#include "Sonchus.h"
#include "SosnowskysHogweed.h"
#include <iostream>
#define SEEDING_PROBABILITY 15

Plant::Plant(World& world) : Organism(world)
{
	world.SetPlantsLength(world.GetPlantsLength() + 1);
}

void Plant::Action()
{
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

	if (rand() % 100 < SEEDING_PROBABILITY)
	{
		Direction direction = Direction(rand() % 8);
		int newX = xPos;
		int newY = yPos;
		switch (direction)
		{
		case N:
			if (yPos > 1 && !world.IsOrganismOnXY(xPos, yPos - 1))
			{
				newY--;
			}
			break;
		case NE:
			if (xPos < world.GetWidth() && yPos > 1 && !world.IsOrganismOnXY(xPos + 1, yPos - 1))
			{
				newX++;
				newY--;
			}
			break;
		case E:
			if (xPos < world.GetWidth() && !world.IsOrganismOnXY(xPos + 1, yPos))
			{
				newX++;
			}
			break;
		case SE:
			if (xPos < world.GetWidth() && yPos < world.GetHeight() && !world.IsOrganismOnXY(xPos + 1, yPos + 1))
			{
				newX++;
				newY++;
			}
			break;
		case S:
			if (yPos < world.GetHeight() && !world.IsOrganismOnXY(xPos, yPos + 1))
			{
				newY++;
			}
			break;
		case SW:
			if (yPos < world.GetHeight() && xPos > 1 && !world.IsOrganismOnXY(xPos - 1, yPos + 1))
			{
				newX--;
				newY++;
			}
			break;
		case W:
			if (xPos > 1 && !world.IsOrganismOnXY(xPos - 1, yPos))
			{
				newX--;
			}
			break;
		case NW:
			if (xPos > 1 && yPos > 1 && !world.IsOrganismOnXY(xPos - 1, yPos - 1))
			{
				newX--;
				newY--;
			}
			break;
		}

		if (newX != xPos || newY != yPos)
		{
			if (dynamic_cast<DeadlyNightshade*>(this))
			{
				world.AddOrganism(new DeadlyNightshade(newX, newY, world));
			}
			else if (dynamic_cast<Grass*>(this))
			{
				world.AddOrganism(new Grass(newX, newY, world));
			}
			else if (dynamic_cast<Guarana*>(this))
			{
				world.AddOrganism(new Guarana(newX, newY, world));
			}
			else if (dynamic_cast<Sonchus*>(this))
			{
				world.AddOrganism(new Sonchus(newX, newY, world));
			}
			else if (dynamic_cast<SosnowskysHogweed*>(this))
			{
				world.AddOrganism(new SosnowskysHogweed(newX, newY, world));
			}
		}
	}
}

void Plant::AddToLogDeath()
{
	world.logs += " -  ";
	world.logs += OrganismName();
	world.logs += " from (";
	world.logs += std::to_string(xPos);
	world.logs += ", ";
	world.logs += std::to_string(yPos);
	world.logs += ") has been eaten.\n";
}

Plant::~Plant()
{
	world.SetPlantsLength(world.GetPlantsLength() - 1);
}