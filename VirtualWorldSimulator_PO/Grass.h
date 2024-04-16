#pragma once
#include "Plant.h"
class Grass : public Plant
{
public:
	Grass(int xPos, int yPos, World& world);
	void Action() override;
	void Collision() override;
	void Print() override;
	~Grass();
};