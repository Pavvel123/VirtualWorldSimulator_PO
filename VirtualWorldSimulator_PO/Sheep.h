#pragma once
#include "Animal.h"
class Sheep : public Animal
{
public:
	Sheep(int xPos, int yPos, World& world);
	void Action(World& world) override;
	void Collision(World& world) override;
	void Print() override;
	~Sheep();
};