#pragma once
#include "Animal.h"
class Antelope : public Animal
{
public:
	Antelope(int xPos, int yPos, World& world);
	Antelope(World& world);
	void Action() override;
	void Collision(Organism* organism) override;
	void Print() override;
	const char* OrganismName() const override;
	~Antelope();
};