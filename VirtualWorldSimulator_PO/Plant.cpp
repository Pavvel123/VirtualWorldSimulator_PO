#include "Plant.h"
Plant::Plant(World& world) : Organism(world)
{
}
/*
Plant::Plant(int strength, int xPos, int yPos, World& world)
	//: Organism(strength, 0, xPos, yPos, world)
{
	Organism::strength = strength;
	Organism::initiative = 0;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}
*/
// symulacja rozprzestrzeniania się rośliny w metodzie akcja() → z pewnym
// prawdopodobieństwem każda z roślin może „zasiać” nową roślinę tego samego gatunku na
// losowym, sąsiednim polu.
void Plant::Action(World& world)
{
}
/*
Plant::~Plant()
{
}
*/