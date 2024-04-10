#pragma once
#include "Animal.h"
class Fox : public Animal
{
	Fox(int strength, int initiative, int xPos, int yPos, World& world);
	void Action(World& world) override;
	void Collision(World& world) override;
	void Print() override;
	~Fox();
};