#pragma once
#include "Plant.h"
class Guarana : public Plant
{
public:
	Guarana(int xPos, int yPos, World& world);
	Guarana(World& world);
	void Action() override;
	void Collision(Organism* organism) override;
	void Print() override;
	const char* OrganismName() const override;
	~Guarana();
};