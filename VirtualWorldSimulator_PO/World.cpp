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

void World::MakeTurn()
{
	for (Organism*& organism : *organisms)
	{
		//organism->Action();
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
