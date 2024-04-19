#pragma once
#include "Animal.h"
class Wolf : public Animal
{
public:
	Wolf(int xPos, int yPos, World& world);
	Wolf(World& world);
	void Action() override;
	void Collision(Organism* organism) override;
	void Print() override;
	const char* OrganismName() const override;
	~Wolf();
};