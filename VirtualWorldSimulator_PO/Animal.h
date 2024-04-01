#pragma once
#include "Organism.h"
class Animal : public Organism
{
public:
	Animal();
	void action() override; // TODO podstawowa forma ruchu
	void collision() override; // TODO rozmna¿anie
	~Animal();
};