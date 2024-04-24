#include "Human.h"
#include <iostream>
#include "MyFunctions.h"
#include <conio.h>
#include <fstream>

using std::cout;
using std::endl;
using std::fstream;

Human::Human(int xPos, int yPos, World& world)
	: Animal(world), activeAlzursShield(false), timeoutAlzursShield(5)
{
	Organism::strength = 5;
	Organism::initiative = 4;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
	Organism::AddToLogBorn();
}

Human::Human(World& world)
	: Animal(world), activeAlzursShield(false), timeoutAlzursShield(5)
{
	int pos[2]{};
	world.RandomPos(pos);
	Organism::strength = 5;
	Organism::initiative = 4;
	Organism::xPos = pos[0];
	Organism::yPos = pos[1];
	Organism::world = world;
	Organism::AddToLogBorn();
}

bool Human::GetActiveAlzursShield() const
{
	return activeAlzursShield;
}

int Human::GetTimeoutAlzursShield() const
{
	return timeoutAlzursShield;
}

void Human::SetActiveAlzursShield(bool value)
{
	activeAlzursShield = value;
}

void Human::SetTimeoutAlzursShield(int value)
{
	timeoutAlzursShield = value;
}

bool Human::IfDefendedTheAttack(Organism* offensive)
{
	if (activeAlzursShield && dynamic_cast<Animal*>(offensive))
	{
		return true;
		world.logs += " !  Human from (";
		world.logs += std::to_string(xPos);
		world.logs += ", ";
		world.logs += std::to_string(yPos);
		world.logs += ") thanks to the Alzur's Shield has defended the";
		world.logs += offensive->OrganismName();
		world.logs += "'s attack!\n";
	}
	else
	{
		return false;
	}
}

void Human::AlzursShieldAction()
{
	if (timeoutAlzursShield > 0)
	{
		timeoutAlzursShield--;
	}

	if (timeoutAlzursShield == 0 && activeAlzursShield)
	{
		activeAlzursShield = false;
		timeoutAlzursShield = 5;
		world.logs += " =! Alzur's Shield deactivated.\n";
	}
}

void Human::AlzursShieldActivation()
{
	if (!activeAlzursShield && timeoutAlzursShield == 0)
	{
		activeAlzursShield = true;
		timeoutAlzursShield = 5;
		Print();
		Gotoxy(2 * world.GetWidth() + 3, 4);
		SetTextColour(96);
		cout << "== Alzur's Shield activated ==";
		SetTextColour(15);
		world.logs += " == Alzur's Shield activated ==\n";
	}
	else if (activeAlzursShield)
	{
		// Alzur's Shield is active; can not be activated now.
		Gotoxy(2 * world.GetWidth() + 3, 4);
		SetTextColour(15);
		cout << "Alzur's Shield is active; can not be activated now.";
		world.logs += " =! Alzur's Shield is active; can not be activated now.\n";
	}
	else
	{
		// Timeout for Alzur's Shield have not passed yet.
		Gotoxy(2 * world.GetWidth() + 3, 4);
		SetTextColour(15);
		cout << "Timeout for Alzur's Shield have not passed yet!";
		world.logs += " =! Timeout for Alzur's Shield have not passed yet!\n";
	}
}

void Human::Action()
{ // 49 - 57
	// N - 224 72
	// S - 224 80
	// E - 224 77
	// W - 224 75
	Gotoxy(2 * world.GetWidth() + 3, 3);
	SetTextColour(15);
	cout << "Human move. Click an arrow...";
	prevXpos = xPos;
	prevYpos = yPos;
	int xPosTemp = xPos;
	int yPosTemp = yPos;
	while (xPosTemp == prevXpos && yPosTemp == prevYpos)
	{
		int input = _getch();
		while (input != 224)
		{
			if (input == 'n')
			{
				AlzursShieldActivation();
			}
			if (input == 's')
			{
				fstream file("SAVE.txt", std::ios::out);
				world.SaveToFile(&file);
			}
			input = _getch();
		}
		int input2 = _getch();
		switch (input2)
		{
		case 72:
			if (yPos != 1)
			{
				yPosTemp--;
				world.logs += "->  Human is going north to (";
			}
			break;
		case 77:
			if (xPos != world.GetWidth())
			{
				xPosTemp++;
				world.logs += "->  Human is going east to (";
			}
			break;
		case 80:
			if (yPos != world.GetHeight())
			{
				yPosTemp++;
				world.logs += "->  Human is going south to (";
			}
			break;
		case 75:
			if (xPos != 1)
			{
				xPosTemp--;
				world.logs += "->  Human is going west to (";
			}
			break;
		default:
			break;
		}
	}
	EreasePrint();
	xPos = xPosTemp;
	yPos = yPosTemp;
	world.logs += std::to_string(xPos);
	world.logs += ", ";
	world.logs += std::to_string(yPos);
	world.logs += ").\n";
	AlzursShieldAction();
}

void Human::Collision(Organism* organism)
{
	//There is only one human on the map. Uncomment if more humans.
	
	//Animal::Collision(organism);
	//if (!dynamic_cast<Human*>(organism))
	//{
		if (organism->IfDefendedTheAttack(this))
		{
			xPos = prevXpos;
			yPos = prevYpos;
			isDead = false;
		}
		else
		{
			if (strength > organism->GetStrength())
			{
				organism->SetIsDead(true);
			}
			else
			{
				isDead = true;
			}
		}
	//}
}

void Human::Print()
{
	Organism::Print();
	if (activeAlzursShield)
	{
		SetTextColour(148);
	}
	else
	{
		SetTextColour(159);
	}
	cout << "HU";
}

const char* Human::OrganismName() const
{
	return "Human";
}

Human::~Human()
{
}
