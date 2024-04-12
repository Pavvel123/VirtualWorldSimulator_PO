#pragma once
#include "Animal.h"
class Antelope : public Animal
{
public:
	Antelope(int xPos, int yPos, World& world);
	void Action(World& world) override;
	void Collision(World& world) override;
	void Print() override;
	~Antelope();
};