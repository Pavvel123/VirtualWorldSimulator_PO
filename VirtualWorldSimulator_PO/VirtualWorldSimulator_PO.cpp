#include <iostream>
#include <conio.h>
#include <vector>
#include "MyFunctions.h"

#include "UserInterface.h"
#include "World.h"
#include "Organism.h"

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
using std::vector;

void TestColour()
{
	for (int i = 0; i < 255; i++)
	{
		SetTextColour(i);
		printf("%d: #### ()()\n", i);
	}
}

int main()
{
	//TestColour();
	///*
	setlocale(LC_ALL, "en_US.UNICODE");
	const char* name = "Pawel";
	const char* surname = "Kurpiewski";
	const char* studentsNumber = "198203";
	unsigned width = 20;
	unsigned height = 20;

	vector<Organism*> organisms;
	World world(width, height, &organisms);
	organisms.push_back(new Fox(5, 6, world));
	organisms.push_back(new Wolf(11, 12, world));
	organisms.push_back(new Human(1, 1, world));
	organisms.push_back(new Antelope(3, 3, world));
	organisms.push_back(new Sheep(7, 12, world));
	organisms.push_back(new Tortoise(9, 2, world));

	organisms.push_back(new DeadlyNightshade(18, 5, world));
	organisms.push_back(new Grass(10, 10, world));
	organisms.push_back(new Guarana(12, 19, world));
	organisms.push_back(new Sonchus(14, 16, world));
	organisms.push_back(new SosnowskysHogweed(16, 17, world));
	UserInterface ui(name, surname, studentsNumber, world);
	ui.Print();
	organisms.clear();
	while (true)
	{
		world.MakeTurn();
	}
	//*/
	_getch();
}