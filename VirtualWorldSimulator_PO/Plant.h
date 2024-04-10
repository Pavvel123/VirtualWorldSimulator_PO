#pragma once
#include "Organism.h"
class Plant : public Organism
{
public:
	Plant(World& world);
	//Plant(int strength, int xPos, int yPos, World& world);
	void Action(World& world) override;
	//~Plant();
};