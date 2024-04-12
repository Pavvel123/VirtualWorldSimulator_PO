#include "UserInterface.h"
#include <iostream>
#include "MyFunctions.h"

using std::cout;
using std::endl;

UserInterface::UserInterface(const char* name, const char* surname, const char* studentsNumber, World& world)
	: name(name), surname(surname), studentsNumber(studentsNumber), world(world)
{
}

void UserInterface::Print() const
{
	unsigned width = world.GetWidth();
	unsigned height = world.GetHeight();

	cout << name << " " << surname << ", " << studentsNumber << "\n\n";

	Gotoxy(0, 2);

	cout << (char)201;
	for (unsigned i = 0; i < 2 * width; i++)
	{
		cout << (char)205;
	}
	cout << (char)187 << endl;
	for (unsigned i = 0; i < height; i++)
	{
		cout << (char)186;
		Gotoxy(2 * width + 1, i + 3);
		cout << (char)186 << endl;
	}
	cout << (char)200;
	for (unsigned i = 0; i < 2 * width; i++)
	{
		cout << (char)205;
	}
	cout << (char)188 << endl;

	world.Print();
}

UserInterface::~UserInterface()
{
}
