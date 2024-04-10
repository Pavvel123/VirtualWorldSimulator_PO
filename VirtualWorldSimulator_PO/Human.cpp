#include "Human.h"

Human::Human(int strength, int initiative, int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = strength;
	Organism::initiative = initiative;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Human::Action(World& world)
{
}

void Human::Collision(World& world)
{
}

void Human::Print()
{
}

Human::~Human()
{
}
