#pragma once
#include "World.h"

class UserInterface
{
private:
	const char* name;
	const char* surname;
	const char* studentsNumber;
	World& world;

public:
	UserInterface(const char* name, const char* surname, const char* studentsNumber, World& world);
	void Print() const;
	~UserInterface();
};