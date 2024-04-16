#pragma once
#include "Animal.h"
class Wolf : public Animal
{
public:
	Wolf(int xPos, int yPos, World& world);
	void Action() override;
	void Collision() override;
	void Print() override;
	~Wolf();
};