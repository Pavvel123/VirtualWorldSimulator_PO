#pragma once
#include "Animal.h"
class Sheep : public Animal
{
public:
	Sheep(int xPos, int yPos, World& world);
	void Action() override;
	void Collision() override;
	void Print() override;
	~Sheep();
};