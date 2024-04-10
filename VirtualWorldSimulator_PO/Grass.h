#pragma once
#include "Plant.h"
class Grass : public Plant
{
	Grass(int strength, int xPos, int yPos, World& world);
	void Action(World& world) override;
	void Collision(World& world) override;
	void Print() override;
	~Grass();
};