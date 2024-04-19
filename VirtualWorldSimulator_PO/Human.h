#pragma once
#include "Animal.h"
class Human : public Animal
{
public:
	Human(int xPos, int yPos, World& world);
	Human(World& world);
	void Action() override; // TODO poruszanie sie
	void Collision(Organism* organism) override; // TODO specjalna umiejetnosc
	void Print() override;
	const char* OrganismName() const override;
	~Human();
};