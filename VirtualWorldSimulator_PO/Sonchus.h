#pragma once
#include "Plant.h"
//Mlecz
class Sonchus : public Plant
{
public:
	Sonchus(int xPos, int yPos, World& world);
	Sonchus(World& world);
	void Action() override;
	void Collision(Organism* organism) override;
	void Print() override;
	const char* OrganismName() const override;
	~Sonchus();
};