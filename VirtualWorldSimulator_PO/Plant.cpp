#include "Plant.h"
Plant::Plant(World& world) : Organism(world)
{
}

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