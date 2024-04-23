#include "Organism.h"
#include "MyFunctions.h"
#include <iostream>
#include "NoMoreSpaceAvailableException.h"

using std::cout;

Organism::Organism(World& world) : strength(0), initiative(0), xPos(0), yPos(0), age(0), isDead(false), world(world)
{
}

void Organism::AddToLogBorn()
{
	world.logs += " *  ";
	world.logs += OrganismName();
	world.logs += " has been added on (";
	world.logs += std::to_string(xPos);
	world.logs += ", ";
	world.logs += std::to_string(yPos);
	world.logs += ").\n";
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

int Organism::GetInitiative() const
{
	return initiative;
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

bool Organism::IfDefendedTheAttack(Organism* offensive)
{
	return false;
}

void Organism::EreasePrint()
{
	if (!isDead)
	{
		Gotoxy(2 * xPos - 1, yPos + 2);
		SetTextColour(8);//128 // 8
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
		}
	}
	return nullptr;
}

void Organism::NewPosIn8Neighbourhood(int* pos)
{
	enum Direction8
	{
		N,
		NE,
		E,
		SE,
		S,
		SW,
		W,
		NW
	}; 

	bool possibleN = true;
	bool possibleNE = true;
	bool possibleE = true;
	bool possibleSE = true;
	bool possibleS = true;
	bool possibleSW = true;
	bool possibleW = true;
	bool possibleNW = true;
	do
	{
		Direction8 direction8 = Direction8(rand() % 8);
		switch (direction8)
		{
		case N:
			if (possibleN && yPos > 1 && !world.IsOrganismOnXY(xPos, yPos - 1))
			{
				pos[1]--;
			}
			else
			{
				possibleN = false;
			}
			break;
		case NE:
			if (possibleNE && xPos < world.GetWidth() && yPos > 1 && !world.IsOrganismOnXY(xPos + 1, yPos - 1))
			{
				pos[0]++;
				pos[1]--;
			}
			else
			{
				possibleNE = false;
			}
			break;
		case E:
			if (possibleE && xPos < world.GetWidth() && !world.IsOrganismOnXY(xPos + 1, yPos))
			{
				pos[0]++;
			}
			else
			{
				possibleE = false;
			}
			break;
		case SE:
			if (possibleSE && xPos < world.GetWidth() && yPos < world.GetHeight() && !world.IsOrganismOnXY(xPos + 1, yPos + 1))
			{
				pos[0]++;
				pos[1]++;
			}
			else
			{
				possibleSE = false;
			}
			break;
		case S:
			if (possibleS && yPos < world.GetHeight() && !world.IsOrganismOnXY(xPos, yPos + 1))
			{
				pos[1]++;
			}
			else
			{
				possibleS = false;
			}
			break;
		case SW:
			if (possibleSW && yPos < world.GetHeight() && xPos > 1 && !world.IsOrganismOnXY(xPos - 1, yPos + 1))
			{
				pos[0]--;
				pos[1]++;
			}
			else
			{
				possibleSW = false;
			}
			break;
		case W:
			if (possibleW && xPos > 1 && !world.IsOrganismOnXY(xPos - 1, yPos))
			{
				pos[0]--;
			}
			else
			{
				possibleW = false;
			}
			break;
		case NW:
			if (possibleNW && xPos > 1 && yPos > 1 && !world.IsOrganismOnXY(xPos - 1, yPos - 1))
			{
				pos[0]--;
				pos[1]--;
			}
			else
			{
				possibleNW = false;
			}
			break;
		default:
			break;
		}

		if (!(possibleN || possibleNE || possibleE || possibleSE || possibleS || possibleSW || possibleW || possibleNW))
		{
			throw NoMoreSpaceAvailableException();
		}
	} while (pos[0] == xPos && pos[1] == yPos);
}

Organism::~Organism()
{
}
