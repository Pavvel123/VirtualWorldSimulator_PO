#pragma once
#include "Animal.h"
class Tortoise : public Animal
{
public:
	Tortoise(int xPos, int yPos, World& world);
	Tortoise(World& world);
	bool IfDefendedTheAttack(Organism* offensive) override;
	void Action() override;
	void Collision(Organism* organism) override;
	void Print() override;
	const char* OrganismName() const override;
	~Tortoise();
};