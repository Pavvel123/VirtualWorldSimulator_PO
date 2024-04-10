#include "Animal.h"
Animal::Animal(World& world) : Organism(world)
{
}
/*
Animal::Animal(int strength, int initiative, int xPos, int yPos, World& world)
	//: Organism(strength, initiative, xPos, yPos, world)
{
	Organism::strength = strength;
	Organism::initiative = initiative;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}
*/
void Animal::Action(World& world)
{
}

void Animal::Collision(World& world)
{
}

void Animal::Print()
{
}
/*
Animal::~Animal()
{
}
*/