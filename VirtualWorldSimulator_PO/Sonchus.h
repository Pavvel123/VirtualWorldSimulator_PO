#pragma once
#include "Plant.h"
//Mlecz
class Sonchus : public Plant
{
	Sonchus(int strength, int xPos, int yPos, World& world);
	void Action(World& world) override;
	void Collision(World& world) override;
	void Print() override;
	~Sonchus();
};