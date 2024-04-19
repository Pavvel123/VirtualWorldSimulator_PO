#pragma once
#include "Plant.h"
// Barszcz Sosnowskiego
class SosnowskysHogweed : public Plant
{
public:
	SosnowskysHogweed(int xPos, int yPos, World& world);
	SosnowskysHogweed(World& world);
	void Action() override;
	void Collision(Organism* organism) override;
	void Print() override;
	const char* OrganismName() const override;
	~SosnowskysHogweed();
};