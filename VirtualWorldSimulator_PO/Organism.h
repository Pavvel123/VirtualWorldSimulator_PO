#pragma once
#include "World.h"

class World;

class Organism
{
protected:
	int strength;
	int initiative;
	int xPos;
	int yPos;
	World& world;

public:
	Organism(World& world);
	int GetXPos() const;
	int GetYPos() const;
	virtual void Action() = 0;
	virtual void Collision() = 0;
	virtual void Print();
	//~Organism();
};