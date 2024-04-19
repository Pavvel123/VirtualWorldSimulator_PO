#pragma once
#include "Animal.h"
class Fox : public Animal
{
public:
	Fox(int xPos, int yPos, World& world);
	Fox(World& world);
	void Action() override;
	void Collision(Organism* organism) override;
	void Print() override;
	bool CanMove(int newX, int newY);
	const char* OrganismName() const override;
	~Fox();
};