#pragma once
#include "Plant.h"
class Grass : public Plant
{
public:
	Grass(int xPos, int yPos, World& world);
	void Action(World& world) override;
	void Collision(World& world) override;
	void Print() override;
	~Grass();
};