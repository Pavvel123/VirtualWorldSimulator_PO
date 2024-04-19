#pragma once
#include "Plant.h"
class Grass : public Plant
{
public:
	Grass(int xPos, int yPos, World& world);
	Grass(World& world);
	void Action() override;
	void Collision(Organism* organism) override;
	void Print() override;
	const char* OrganismName() const override;
	~Grass();
};