#include "Organism.h"
#include "MyFunctions.h"
#include <iostream>

using std::cout;

Organism::Organism(World& world) : strength(0), initiative(0), xPos(0), yPos(0), age(0), isDead(false), world(world)
{
}

int Organism::GetXPos() const
{
	return xPos;
}

int Organism::GetYPos() const
{
	return yPos;
}

int Organism::GetAge() const
{
	return age;
}

bool Organism::GetIsDead() const
{
	return isDead;
}

int Organism::GetStrength() const
{
	return strength;
}

void Organism::SetAge(int age)
{
	this->age = age;
}

void Organism::SetIsDead(bool isDead)
{
	this->isDead = isDead;
}

void Organism::SetStrength(int strength)
{
	this->strength = strength;
}

void Organism::Print()
{
	Gotoxy(2 * xPos - 1, yPos + 2);
}

bool Organism::IfCounteredTheAtack(Organism* offensive)
{
	return false;
}

void Organism::EreasePrint()
{
	//if (!world.IsOrganismOnXY(xPos, yPos))
	if (!isDead)
	{
		Gotoxy(2 * xPos - 1, yPos + 2);
		SetTextColour(128);//8
		if ((xPos % 2 == 0 && yPos % 2 == 1) || (xPos % 2 == 1 && yPos % 2 == 0))
		{
			cout << (char)176 << (char)176;
		}
		else
		{
			cout << "  ";
		}
	}
}

Organism* Organism::CollidedWith()
{
	int organismsLength = (int)world.GetOrganisms()->size();
	bool foundSelf = false;
	for (int o = 0; o < organismsLength; o++)
	{
		//int testXPos = (*organisms)[o]->GetXPos();
		//int testYPos = (*organisms)[o]->GetYPos();
		if ((*world.GetOrganisms())[o]->GetXPos() == xPos && (*world.GetOrganisms())[o]->GetYPos() == yPos)
		{
			if (this->OrganismName() == (*world.GetOrganisms())[o]->OrganismName())
			{
				if (foundSelf)
				{
					return (*world.GetOrganisms())[o];
				}
				else
				{
					foundSelf = true;
				}
			}
			else
			{
				return (*world.GetOrganisms())[o];
			}

			//if (foundSelf) return (*world.GetOrganisms())[o];
		}
	}
	return nullptr;
}

Organism::~Organism()
{
}
