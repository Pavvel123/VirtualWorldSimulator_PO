#pragma once
#include "World.h"
struct Location
{
	int x;
	int y;
};


class Organism
{
private:
	int strength;
	int initiative;
	Location location;
	World world;

public:
	Organism();
	virtual void action() = 0;
	virtual void collision() = 0;
	virtual void print() = 0;
	~Organism();
};