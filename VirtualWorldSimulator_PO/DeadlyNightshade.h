#pragma once
#include "Plant.h"
// Wilcza Jagoda
class DeadlyNightshade : public Plant
{
public:
	DeadlyNightshade(int xPos, int yPos, World& world);
	DeadlyNightshade(World& world);
	void Action() override;
	void Collision(Organism* organism) override;
	void Print() override;
	const char* OrganismName() const override;
	~DeadlyNightshade();
};