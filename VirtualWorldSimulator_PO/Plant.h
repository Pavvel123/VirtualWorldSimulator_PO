#pragma once
#include "Organism.h"
class Plant : public Organism
{
public:
	Plant();
	void action() override;
	~Plant();
};