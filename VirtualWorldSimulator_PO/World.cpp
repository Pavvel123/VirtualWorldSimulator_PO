#include "World.h"
#include <iostream>
#include <cmath>
#include "MyFunctions.h"

using std::cout;

World::World(unsigned width, unsigned height, vector<Organism*>* organisms)
	: width(width), height(height), organisms(organisms)
{
}

void World::AddOrganism(Organism* organism)
{
	organisms->push_back(organism);
}

unsigned World::GetWidth() const
{
	return width;
}

unsigned World::GetHeight() const
{
	return height;
}

bool World::IsOrganismOnXY(int x, int y)
{
	for (Organism*& organism : *organisms)
	{
		if (organism->GetXPos() == x && organism->GetYPos() == y)
		{
			return true;
		}
	}
	return false;
}

bool World::HasOrganismColided(const Organism& organism)
{
	int organismsLength = organisms->size();
	bool foundSelf = false;
	int thisXPos = organism.GetXPos();
	int thisYPos = organism.GetYPos();
	for (int o = 0; o < organismsLength; o++)
	{
		//int testXPos = (*organisms)[o]->GetXPos();
		//int testYPos = (*organisms)[o]->GetYPos();
		if ((*organisms)[o]->GetXPos() == thisXPos && (*organisms)[o]->GetYPos() == thisYPos)
		{
			if (foundSelf) return true;
			else foundSelf = true;
		}
	}
	return false;
}

void World::MakeTurn()
{
	int organismsLength = organisms->size();
	for (int i = 0; i < organismsLength; i++)
	{
		(*organisms)[i]->Action();
		if (HasOrganismColided(*(*organisms)[i]))
		{
			(*organisms)[i]->Collision();
		}
		(*organisms)[i]->Print();
	}
}

void World::Print()
{
	//Gotoxy(1, 3);
	SetTextColour(8);//127
	for (unsigned h = 0; h < height; h++)
	{
		Gotoxy(1, h + 3);
		if (h % 2 == 0)
		{
			for (unsigned w = 0; w < width / 2; w++)
			{
				cout << "  ";
				cout << (char)176 << (char)176;
			}
		}
		else
		{
			for (unsigned w = 0; w < width / 2; w++)
			{
				cout << (char)176 << (char)176;
				cout << "  ";
			}
			if (width % 2 == 1)
			{
				cout << (char)176 << (char)176;
			}
		}
		cout << "\n";
	}
	for (Organism*& organism : *organisms)
	{
		organism->Print();
	}
	SetTextColour(15);
}

World::~World()
{
}
