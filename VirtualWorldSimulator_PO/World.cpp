#include "World.h"
#include <iostream>
#include <cmath>
#include "MyFunctions.h"
#include <conio.h>
#include "Human.h"
#include <algorithm>

using std::cout;
using std::endl;

World::World(int width, int height, vector<Organism*>* organisms)
	: width(width), height(height), organisms(organisms)
{
}

void World::AddOrganism(Organism* organism)
{
	organisms->push_back(organism);
}

void World::DeleteOrganism(Organism* organism)
{// TODO: dodaæ pole dead do organizmu
	//organisms->erase()
}

int World::GetAnimalsLength() const
{
	return animalsLength;
}

int World::GetPlantsLength() const
{
	return plantsLength;
}

int World::GetWidth() const
{
	return width;
}

int World::GetHeight() const
{
	return height;
}

vector<Organism*>* World::GetOrganisms() const
{
	return organisms;
}

void World::SetAnimalsLength(int value)
{
	animalsLength = value;
}

void World::SetPlantsLength(int value)
{
	plantsLength = value;
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

int* World::RandomPos(int* output)
{
	do
	{
		output[0] = rand() % width + 1;
		output[1] = rand() % height + 1;
	} while (IsOrganismOnXY(output[0], output[1]));
	return output;
}

void World::SortOrganisms()
{
	std::sort(organisms->begin(), organisms->end(), [](const Organism * a, const Organism * b)
	{
			if (a->GetInitiative() != b->GetInitiative())
			{
				return a->GetInitiative() > b->GetInitiative();
			}
			else
			{
				return a->GetAge() > b->GetAge();
			}
	});
}

void World::MakeTurn()
{
	int organismsLength = animalsLength + plantsLength;
	for (int i = 0; i < organismsLength; i++)
	{
		if (!dynamic_cast<Human*>((*organisms)[i]))
		{
			(*organisms)[i]->EreasePrint();
		}

		if ((*organisms)[i]->GetIsDead())
		{
			//(*organisms)[i]->Collision((*organisms)[i]->CollidedWith());
			delete (*organisms)[i];
			organisms->erase(organisms->begin() + i);
			organismsLength--;
		}
		else
		{
			Gotoxy(2 * width + 5, i + 3);
			(*organisms)[i]->Action();
			Organism* organismColidedWith = (*organisms)[i]->CollidedWith();
			if (organismColidedWith != nullptr)
			{
				(*organisms)[i]->Collision(organismColidedWith);
				if ((*organisms)[i]->OrganismName() != organismColidedWith->OrganismName())
				{
					organismColidedWith->Collision((*organisms)[i]);
				}
			}
			if (!(*organisms)[i]->GetIsDead())
			{
				(*organisms)[i]->Print();
			}
			(*organisms)[i]->SetAge((*organisms)[i]->GetAge() + 1);
			/*int input;
			do
			{
				input = _getch();
			} while (input != 13);*/
		}
	}
	//Gotoxy(2 * width + 5, 3);// organismsLength + 3);
	//SetTextColour(160);
	//cout << "END OF TURN! Press enter to continue.";
	/*
	int input;
	do
	{
		input = _getch();
	} while (input != 13);*/

	SetTextColour(15);
	for (int i = 0; i < animalsLength + 1; i++)
	{
		//Gotoxy(2 * width + 5, i + 3);
		//cout << "______________________________________________________________________";
	}
	SortOrganisms();
}

void World::Print()
{
	//Gotoxy(1, 3);
	SetTextColour(8);//128
	for (int h = 0; h < height; h++)
	{
		Gotoxy(1, h + 3);
		if (h % 2 == 0)
		{
			for (int w = 0; w < width / 2; w++)
			{
				cout << "  ";
				cout << (char)176 << (char)176;
			}
		}
		else
		{
			for (int w = 0; w < width / 2; w++)
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
