#pragma once
#include "Organism.h"
class Animal : public Organism
{
public:
	Animal(World& world);
	//Animal(int strength, int initiative, int xPos, int yPos, World& world);
	virtual void Action(World& world) override; // TODO podstawowa forma ruchu
	virtual void Collision(World& world) override; // TODO rozmna¿anie
	virtual void Print() override = 0;
	//~Animal();
};