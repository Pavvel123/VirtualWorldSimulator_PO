#include "UserInterface.h"
#include <iostream>

using std::cout;
using std::endl;

UserInterface::UserInterface(const char* name, const char* surname, const char* studentsNumber, World& world)
	: name(name), surname(surname), studentsNumber(studentsNumber), world(world)
{
}

void UserInterface::Print() const
{
	cout << name << " " << surname << ", " << studentsNumber << endl;
}

UserInterface::~UserInterface()
{
}
