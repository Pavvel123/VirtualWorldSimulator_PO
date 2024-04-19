#pragma once
#include "Animal.h"
class Tortoise : public Animal
{
public:
	Tortoise(int xPos, int yPos, World& world);
	Tortoise(World& world);
	void Action() override;
	void Collision(Organism* organism) override;
	void Print() override;
	const char* OrganismName() const override;
	~Tortoise();
};