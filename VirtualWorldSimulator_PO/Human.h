#pragma once
#include "Animal.h"
class Human : public Animal
{
public:
	Human();
	void action() override; // TODO poruszanie sie
	void collision() override; // TODO specjalna umiejetnosc
	~Human();
};