#pragma once
#include "Plant.h"
// Barszcz Sosnowskiego
class SosnowskysHogweed : public Plant
{
public:
	SosnowskysHogweed(int xPos, int yPos, World& world);
	void Action() override;
	void Collision() override;
	void Print() override;
	~SosnowskysHogweed();
};