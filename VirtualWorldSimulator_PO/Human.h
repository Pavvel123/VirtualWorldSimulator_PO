#pragma once
#include "Animal.h"
class Human : public Animal
{
public:
	Human(int xPos, int yPos, World& world);
	void Action(World& world) override; // TODO poruszanie sie
	void Collision(World& world) override; // TODO specjalna umiejetnosc
	void Print() override;
	~Human();
};