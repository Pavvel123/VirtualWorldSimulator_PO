#pragma once
#include "Animal.h"
class Wolf : public Animal
{
public:
	Wolf(int xPos, int yPos, World& world);
	void Action(World& world) override;
	void Collision(World& world) override;
	void Print() override;
	~Wolf();
};