#include "Animal.h"
#include "MyFunctions.h"
Animal::Animal(World& world) : Organism(world)
{
}

void Animal::Action(World& world)
{
}

void Animal::Collision(World& world)
{
}

void Animal::Print()
{
	SetTextColour(207);//196
}

/*
Animal::~Animal()
{
}
*/