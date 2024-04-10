#include <iostream>
#include "UserInterface.h"
#include <string>
#include <vector>
#include "Human.h"
#include "Organism.h"
#include "World.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	setlocale(LC_ALL, "pl-pl");
	const char* name = "Paweł";
	const char* surname = "Kurpiewski";
	const char* studentsNumber = "198203";
	unsigned width = 20;
	unsigned height = 20;
	vector<Organism*> organisms;
	World world(width, height, organisms);
	//World world(width, height);
	Human human(5, 4, 0, 0, world);
	organisms.push_back(&human);
	//world.SetOrganisms(organisms);
	UserInterface ui(name, surname, studentsNumber, world);
	ui.Print();
}