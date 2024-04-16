#include "Plant.h"
#define SEEDING_PROBABILITY 50

enum Direction
{
	N,
	NE,
	E,
	SE,
	S,
	SW,
	W,
	NW
};

Plant::Plant(World& world) : Organism(world)
{
}

// symulacja rozprzestrzeniania się rośliny w metodzie akcja() → z pewnym
// prawdopodobieństwem każda z roślin może „zasiać” nową roślinę tego samego gatunku na
// losowym, sąsiednim polu.
void Plant::Action()
{
}
/*
Plant::~Plant()
{
}
*/