#pragma once
#include "Animal.h"
class Tortoise : public Animal
{
public:
	Tortoise(int xPos, int yPos, World& world);
	void Action() override;
	void Collision() override;
	void Print() override;
	~Tortoise();
};