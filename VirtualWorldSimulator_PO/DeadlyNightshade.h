#pragma once
#include "Plant.h"
// Wilcza Jagoda
class DeadlyNightshade : public Plant
{
public:
	DeadlyNightshade(int xPos, int yPos, World& world);
	void Action() override;
	void Collision() override;
	void Print() override;
	~DeadlyNightshade();
};