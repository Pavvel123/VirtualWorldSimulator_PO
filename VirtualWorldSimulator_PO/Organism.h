#pragma once
#include "World.h"

class World;

class Organism
{
protected:
	int strength;
	int initiative;
	int xPos;
	int yPos;
	int age;
	bool isDead;
	World& world;

public:
	Organism(World& world);
	void AddToLogBorn();

	int GetXPos() const;
	int GetYPos() const;
	int GetAge() const;
	bool GetIsDead() const;
	int GetStrength() const;
	int GetInitiative() const;

	void SetAge(int age);
	void SetIsDead(bool isDead);
	void SetStrength(int strength);

	virtual void Action() = 0;
	virtual void Collision(Organism* organism) = 0;
	virtual void Print();
	virtual bool IfDefendedTheAttack(Organism* offensive);

	void EreasePrint();
	Organism* CollidedWith();
	virtual const char* OrganismName() const = 0;
	void NewPosIn8Neighbourhood(int* pos);


	virtual void AddToLogDeath() = 0;
	virtual ~Organism();
};