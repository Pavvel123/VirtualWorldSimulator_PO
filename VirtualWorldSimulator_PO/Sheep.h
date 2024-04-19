#pragma once
#include "Animal.h"
class Sheep : public Animal
{
public:
	Sheep(int xPos, int yPos, World& world);
	Sheep(World& world);
	void Action() override;
	void Collision(Organism* organism) override;
	void Print() override;
	const char* OrganismName() const override;
	~Sheep();
};