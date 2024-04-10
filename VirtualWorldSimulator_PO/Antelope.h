#pragma once
#include "Animal.h"
class Antelope : public Animal
{
	Antelope(int strength, int initiative, int xPos, int yPos, World& world);
	void Action(World& world) override;
	void Collision(World& world) override;
	void Print() override;
	~Antelope();
};