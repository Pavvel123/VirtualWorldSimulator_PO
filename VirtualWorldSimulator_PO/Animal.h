#pragma once
#include "Organism.h"
class Animal : public Organism
{
public:
	Animal(World& world);
	virtual void Action() override; // TODO podstawowa forma ruchu
	virtual void Collision() override; // TODO rozmnażanie
	virtual void Print() override;
	//~Animal();
};