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

	int GetXPos() const;
	int GetYPos() const;
	int GetAge() const;
	bool GetIsDead() const;
	int GetStrength() const;

	void SetAge(int age);
	void SetIsDead(bool isDead);
	void SetStrength(int strength);

	virtual void Action() = 0;
	virtual void Collision(Organism* organism) = 0;
	virtual void Print();
	virtual bool IfCounteredTheAtack(Organism* offensive);

	void EreasePrint();
	Organism* CollidedWith();
	virtual const char* OrganismName() const = 0;
	virtual ~Organism();
};