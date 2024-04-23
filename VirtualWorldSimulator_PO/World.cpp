#include "World.h"
#include <iostream>
#include <cmath>
#include "MyFunctions.h"
#include <conio.h>
#include <algorithm>
#include "NoMoreSpaceAvailableException.h"

#include "Human.h"
#include "Antelope.h"
#include "Fox.h"
#include "Sheep.h"
#include "Tortoise.h"
#include "Wolf.h"

#include "DeadlyNightshade.h"
#include "Grass.h"
#include "Guarana.h"
#include "Sonchus.h"
#include "SosnowskysHogweed.h"

using std::cout;
using std::endl;

World::World(int width, int height)
	: animalsLength(0), plantsLength(0), width(width), height(height), logs("")
{
	organisms = new vector<Organism*>();
	World& world = *this;
	organisms->push_back(new Fox(world));
	organisms->push_back(new Fox(world));
	organisms->push_back(new Wolf(world));
	organisms->push_back(new Wolf(world));

	organisms->push_back(new Antelope(world));
	organisms->push_back(new Antelope(world));
	organisms->push_back(new Human(world));
	organisms->push_back(new Sheep(world));
	organisms->push_back(new Sheep(world));
	organisms->push_back(new Tortoise(world));
	organisms->push_back(new Tortoise(world));

	organisms->push_back(new DeadlyNightshade(world));
	organisms->push_back(new Grass(world));
	organisms->push_back(new Guarana(world));
	organisms->push_back(new Sonchus(world));
	organisms->push_back(new SosnowskysHogweed(world));
}

World::World(fstream* file)
{
	if (file->good())
	{
		logs = "";
		animalsLength = 0;
		plantsLength = 0;
		World& w = *this;
		string line = "";
		getline(*file, line);
		width = 10 * (line[0] - '0') + line[1] - '0';
		height = 10 * (line[3] - '0') + line[4] - '0';
		organisms = new vector<Organism*>();
		while (getline(*file, line))
		{
			int xPos = 10 * (line[1] - '0') + line[2] - '0';
			int yPos = 10 * (line[4] - '0') + line[5] - '0';
			switch (line[0])
			{
			case 'A':
				Antelope* antelope;
				antelope = new Antelope(xPos, yPos, w);
				organisms->push_back(antelope);
				break;
			case 'D':
				DeadlyNightshade* deadlyNightshade;
				deadlyNightshade = new DeadlyNightshade(xPos, yPos, w);
				organisms->push_back(deadlyNightshade);
				break;
			case 'F':
				Fox* fox;
				fox = new Fox(xPos, yPos, w);
				organisms->push_back(fox);
				break;
			case 'G':
				Grass* grass;
				grass = new Grass(xPos, yPos, w);
				organisms->push_back(grass);
				break;
			case 'U':
				Guarana* guarana;
				guarana = new Guarana(xPos, yPos, w);
				organisms->push_back(guarana);
				break;
			case 'H':
				Human* human;
				human = new Human(xPos, yPos, w);
				organisms->push_back(human);
				break;
			case 'S':
				Sheep* sheep;
				sheep = new Sheep(xPos, yPos, w);
				organisms->push_back(sheep);
				break;
			case 'O':
				Sonchus* sonchus;
				sonchus = new Sonchus(xPos, yPos, w);
				organisms->push_back(sonchus);
				break;
			case 'E':
				SosnowskysHogweed* sosnowskysHogweed;
				sosnowskysHogweed = new SosnowskysHogweed(xPos, yPos, w);
				organisms->push_back(sosnowskysHogweed);
				break;
			case 'T':
				Tortoise* tortoise;
				tortoise = new Tortoise(xPos, yPos, w);
				organisms->push_back(tortoise);
				break;
			case 'W':
				Wolf* wolf;
				wolf = new Wolf(xPos, yPos, w);
				organisms->push_back(wolf);
				break;
			default:
				break;
			}
		}
		file->close();
	}
}

void World::AddOrganism(Organism* organism)
{
	organisms->push_back(organism);
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

string World::GetLogs() const
{
	return logs;
}

void World::SetAnimalsLength(int value)
{
	animalsLength = value;
}

void World::SetPlantsLength(int value)
{
	plantsLength = value;
}

void World::AddToLogs(const char* log)
{
	logs += log;
}

void World::ClearLogs()
{
	logs.clear();
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
	std::sort(organisms->begin(), organisms->end(), [](const Organism* a, const Organism* b)
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

int World::MakeTurn()
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
			if (dynamic_cast<Human*>((*organisms)[i]))
			{
				logs += " ++ Human is dead ++";
				SetTextColour(15);
				Gotoxy(0, height + 5);
				cout << logs << '\n';
				Gotoxy(2 * width + 5, 3);
				SetTextColour(15);
				cout << "Human is dead. End of game.";
				return 0;
			}
			delete (*organisms)[i];
			organisms->erase(organisms->begin() + i);
			organismsLength--;
		}
		else
		{
			Gotoxy(2 * width + 5, i + 3);
			try
			{
				(*organisms)[i]->Action();
			}
			catch (NoMoreSpaceAvailableException& e)
			{
				(*organisms)[i]->SetIsDead(true);
				i--;
				continue;
			}
			Organism* organismColidedWith = (*organisms)[i]->CollidedWith();
			if (organismColidedWith != nullptr)
			{
				(*organisms)[i]->Collision(organismColidedWith);
				if ((*organisms)[i]->OrganismName() != organismColidedWith->OrganismName() && (*organisms)[i]->GetXPos() == organismColidedWith->GetXPos() && (*organisms)[i]->GetYPos() == organismColidedWith->GetYPos())
				{
					organismColidedWith->Collision((*organisms)[i]);
				}
				if (!organismColidedWith->GetIsDead())
				{
					organismColidedWith->Print();
				}
			}
			(*organisms)[i]->Print();
			(*organisms)[i]->SetAge((*organisms)[i]->GetAge() + 1);
		}
	}

	SetTextColour(15);
	Gotoxy(0, height + 5);
	cout << logs << '\n';

	SortOrganisms();
	return 1;
}

void World::Print()
{
	SetTextColour(8);
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

void World::SaveToFile(fstream* file)
{
	if (file->is_open())
	{
		if (width < 10)
		{
			*file << '0';
		}
		*file << width << 'x';
		if (height < 10)
		{
			*file << '0';
		}
		*file << height << '\n';
		for (Organism*& organism : *organisms)
		{
			int xPos = organism->GetXPos();
			int yPos = organism->GetYPos();
			if (dynamic_cast<Antelope*>(organism)) *file << 'A';
			else if (dynamic_cast<DeadlyNightshade*>(organism)) *file << 'D';
			else if (dynamic_cast<Fox*>(organism)) *file << 'F';
			else if (dynamic_cast<Grass*>(organism)) *file << 'G';
			else if (dynamic_cast<Guarana*>(organism)) *file << 'U';
			else if (dynamic_cast<Human*>(organism)) *file << 'H';
			else if (dynamic_cast<Sheep*>(organism)) *file << 'S';
			else if (dynamic_cast<Sonchus*>(organism)) *file << 'O';
			else if (dynamic_cast<SosnowskysHogweed*>(organism)) *file << 'E';
			else if (dynamic_cast<Tortoise*>(organism)) *file << 'T';
			else if (dynamic_cast<Wolf*>(organism)) *file << 'W';
			
			if (xPos < 10) *file << '0';
			*file << xPos << ',';
			if (yPos < 10) *file << '0';
			*file << yPos << '\n';
		}
		file->close();
	}
}

World::~World()
{
	delete organisms;
}