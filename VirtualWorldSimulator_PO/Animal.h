#pragma once
#include "Organism.h"
class Animal : public Organism
{
public:
	Animal(World& world);
	virtual void Action(World& world) override; // TODO podstawowa forma ruchu
	virtual void Collision(World& world) override; // TODO rozmna¿anie
	virtual void Print();
	//~Animal();
};