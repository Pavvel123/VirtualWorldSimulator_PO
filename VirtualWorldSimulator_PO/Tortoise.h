#pragma once
#include "Animal.h"
class Tortoise : public Animal
{
public:
	Tortoise(int xPos, int yPos, World& world);
	void Action(World& world) override;
	void Collision(World& world) override;
	void Print() override;
	~Tortoise();
};