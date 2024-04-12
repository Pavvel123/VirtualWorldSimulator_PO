#pragma once
#include "Plant.h"
//Mlecz
class Sonchus : public Plant
{
public:
	Sonchus(int xPos, int yPos, World& world);
	void Action(World& world) override;
	void Collision(World& world) override;
	void Print() override;
	~Sonchus();
};