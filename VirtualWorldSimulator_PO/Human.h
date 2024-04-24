#pragma once
#include "Animal.h"
class Human : public Animal
{
private:
	bool activeAlzursShield;
	int timeoutAlzursShield;
	void AlzursShieldAction();
	void AlzursShieldActivation();
public:
	Human(int xPos, int yPos, World& world);
	Human(World& world);
	bool GetActiveAlzursShield() const;
	int GetTimeoutAlzursShield() const;
	void SetActiveAlzursShield(bool value);
	void SetTimeoutAlzursShield(int value);
	bool IfDefendedTheAttack(Organism* offensive) override;
	void Action() override;
	void Collision(Organism* organism) override;
	void Print() override;
	const char* OrganismName() const override;
	~Human();
};