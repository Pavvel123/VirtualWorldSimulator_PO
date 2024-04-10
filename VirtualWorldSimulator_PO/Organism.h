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
	//Organism(int strength, int initiative, int xPos, int yPos, World& world);
	//Organism(int strength, int initiative, int xPos, int yPos);
	virtual void Action(World& world) = 0;
	virtual void Collision(World& world) = 0;
	virtual void Print() = 0;
	//~Organism();
};