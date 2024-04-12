#pragma once
#include "Plant.h"
// Barszcz Sosnowskiego
class SosnowskysHogweed : public Plant
{
public:
	SosnowskysHogweed(int xPos, int yPos, World& world);
	void Action(World& world) override;
	void Collision(World& world) override;
	void Print() override;
	~SosnowskysHogweed();
};