#pragma once
#include "Animal.h"
class Fox : public Animal
{
public:
	Fox(int xPos, int yPos, World& world);
	void Action(World& world) override;
	void Collision(World& world) override;
	void Print() override;
	~Fox();
};