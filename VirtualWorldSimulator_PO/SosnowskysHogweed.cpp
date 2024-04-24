#include "SosnowskysHogweed.h"
#include "MyFunctions.h"
#include <iostream>
#include "Animal.h"

using std::cout;

SosnowskysHogweed::SosnowskysHogweed(int xPos, int yPos, World& world)
	: Plant(world)
{
	Organism::strength = 10;
	Organism::initiative = 0;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
	Organism::AddToLogBorn();
}

SosnowskysHogweed::SosnowskysHogweed(World& world)
	: Plant(world)
{
	int pos[2]{};
	world.RandomPos(pos);
	Organism::strength = 10;
	Organism::initiative = 0;
	Organism::xPos = pos[0];
	Organism::yPos = pos[1];
	Organism::world = world;
	Organism::AddToLogBorn();
}

void SosnowskysHogweed::Action()
{
	Plant::Action();
	for (Organism*& organism : *world.GetOrganisms())
	{
		if (dynamic_cast<Animal*>(organism))
		{
			for (int i = -1; i <= 1; i++)
			{
				for (int k = -1; k <= 1; k++)
				{
					if (organism->GetXPos() == xPos + i && organism->GetYPos() == yPos + k && !(i == 0 && k == 0))
					{
						organism->EreasePrint();
						organism->SetIsDead(true);
						break;
					}
				}
			}
		}
	}
}

void SosnowskysHogweed::Collision(Organism* organism)
{
	organism->SetIsDead(true);
}

void SosnowskysHogweed::Print()
{
	Organism::Print();
	SetTextColour(161);
	cout << "SH";
}

const char* SosnowskysHogweed::OrganismName() const
{
	return "Sosnowsky's Hogweed";
}

SosnowskysHogweed::~SosnowskysHogweed()
{
	AddToLogDeath();
}