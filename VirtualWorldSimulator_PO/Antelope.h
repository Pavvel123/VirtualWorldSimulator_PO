#pragma once
#include "Animal.h"
class Antelope : public Animal
{
public:
	Antelope(int xPos, int yPos, World& world);
	void Action() override;
	void Collision() override;
	void Print() override;
	~Antelope();
};