#pragma once
#include "Organism.h"
class Plant : public Organism
{
public:
	Plant(World& world);
	void Action(World& world) override;
	//~Plant();
};