#pragma once
#include "Plant.h"
class Guarana : public Plant
{
public:
	Guarana(int xPos, int yPos, World& world);
	void Action(World& world) override;
	void Collision(World& world) override;
	void Print() override;
	~Guarana();
};