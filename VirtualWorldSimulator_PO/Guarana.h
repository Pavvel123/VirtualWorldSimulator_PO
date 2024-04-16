#pragma once
#include "Plant.h"
class Guarana : public Plant
{
public:
	Guarana(int xPos, int yPos, World& world);
	void Action() override;
	void Collision() override;
	void Print() override;
	~Guarana();
};