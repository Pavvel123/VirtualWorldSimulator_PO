#pragma once
#include "Organism.h"
class Animal : public Organism
{
protected:
	int prevXpos;
	int prevYpos;
public:
	Animal(World& world);
	virtual void Action() override;
	virtual void Collision(Organism* organism) override;
	void AddToLogDeath() override;
	virtual ~Animal() override;
};