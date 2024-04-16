#pragma once
#include "Animal.h"
class Fox : public Animal
{
public:
	Fox(int xPos, int yPos, World& world);
	void Action() override;
	void Collision() override;
	void Print() override;
	~Fox();
};