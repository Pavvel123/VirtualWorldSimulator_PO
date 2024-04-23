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
			bool cond1 = organism->GetXPos() == xPos + 1 && organism->GetYPos() == yPos + 1;
			bool cond2 = organism->GetXPos() == xPos + 1 && organism->GetYPos() == yPos;
			bool cond3 = organism->GetXPos() == xPos + 1 && organism->GetYPos() == yPos - 1;
			bool cond4 = organism->GetXPos() == xPos && organism->GetYPos() == yPos + 1;
			bool cond5 = organism->GetXPos() == xPos && organism->GetYPos() == yPos - 1;
			bool cond6 = organism->GetXPos() == xPos - 1 && organism->GetYPos() == yPos + 1;
			bool cond7 = organism->GetXPos() == xPos - 1 && organism->GetYPos() == yPos;
			bool cond8 = organism->GetXPos() == xPos - 1 && organism->GetYPos() == yPos - 1;
			if (cond1 || cond2 || cond3 || cond4 || cond5 || cond6 || cond7 || cond8)
			{
				organism->EreasePrint();
				organism->SetIsDead(true);
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