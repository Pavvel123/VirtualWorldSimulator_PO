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

int main()
{
	///*
	setlocale(LC_ALL, "en_US.UNICODE");
	srand((unsigned)time(nullptr));
	SetTextColour(15);
	const char* name = "Pawel";
	const char* surname = "Kurpiewski";
	const char* studentsNumber = "198203";
	int width = 20;
	int height = 20;

	vector<Organism*> organisms;
	World world(width, height, &organisms);

	organisms.push_back(new Fox(world));
	organisms.push_back(new Wolf(world));
	//organisms.push_back(new Wolf(world));
	//organisms.push_back(new Wolf(world));
	//organisms.push_back(new Wolf(world));
	//organisms.push_back(new Wolf(world));

	organisms.push_back(new Human(world));
	organisms.push_back(new Antelope(world));
	//organisms.push_back(new Antelope(world));
	organisms.push_back(new Sheep(world));
	organisms.push_back(new Tortoise(world));
	
	organisms.push_back(new DeadlyNightshade(world));
	organisms.push_back(new Grass(world));
	organisms.push_back(new Guarana(world));
	organisms.push_back(new Sonchus(world));
	organisms.push_back(new SosnowskysHogweed(world));
	UserInterface ui(name, surname, studentsNumber, world);
	ui.Print();
	//organisms.clear();
	while (true)
	{
		world.MakeTurn();
	}
	//*/
	_getch();
}