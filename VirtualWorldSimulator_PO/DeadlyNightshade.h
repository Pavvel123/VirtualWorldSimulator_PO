#pragma once
#include "Plant.h"
// Wilcza Jagoda
class DeadlyNightshade : public Plant
{
public:
	DeadlyNightshade(int xPos, int yPos, World& world);
	void Action(World& world) override;
	void Collision(World& world) override;
	void Print() override;
	~DeadlyNightshade();
};