#pragma once
#include "Plant.h"
//Mlecz
class Sonchus : public Plant
{
public:
	Sonchus(int xPos, int yPos, World& world);
	void Action() override;
	void Collision() override;
	void Print() override;
	~Sonchus();
};