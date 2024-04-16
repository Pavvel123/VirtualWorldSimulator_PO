#pragma once
#include "Animal.h"
class Human : public Animal
{
public:
	Human(int xPos, int yPos, World& world);
	void Action() override; // TODO poruszanie sie
	void Collision() override; // TODO specjalna umiejetnosc
	void Print() override;
	~Human();
};