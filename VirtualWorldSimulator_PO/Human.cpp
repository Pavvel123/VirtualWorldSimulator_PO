#include "Human.h"
#include <iostream>
#include "MyFunctions.h"
#include <conio.h>

using std::cout;
using std::endl;

Human::Human(int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = 5;
	Organism::initiative = 4;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

Human::Human(World& world)
	: Animal(world)
{
	int pos[2]{};
	world.RandomPos(pos);
	Organism::strength = 5;
	Organism::initiative = 4;
	Organism::xPos = pos[0];
	Organism::yPos = pos[1];
	Organism::world = world;
}

void Human::Action()
{ // 49 - 57
	// N - 224 72
	// S - 224 80
	// E - 224 77
	// W - 224 75
	//SetTextColour(15);
	//cout << "Human move. Click an arrow...";
	int input = _getch();
	while (input != 224)
	{
		input = _getch();
	}
	int input2 = _getch();
	EreasePrint();
	switch (input2)
	{
	case 72:
		if (yPos == 1) yPos++;
		else yPos--;
		break;
	case 77:
		if (xPos == world.GetWidth()) xPos--;
		else xPos++;
		break;
	case 80:
		if (yPos == world.GetHeight()) yPos--;
		else yPos++;
		break;
	case 75:
		if (xPos == 1) xPos++;
		else xPos--;
		break;
	default:
		break;
	}

}

void Human::Collision(Organism* organism)
{
	//There is only one human on the map. Uncomment if more humans.
	
	//Animal::Collision(organism);
	//if (!dynamic_cast<Human*>(organism))
	//{
		if (strength > organism->GetStrength())
		{
			organism->SetIsDead(true);
		}
		else
		{
			isDead = true;
		}
	//}
}

void Human::Print()
{
	Organism::Print();
	SetTextColour(148);//159
	std::cout << "HU";
}

const char* Human::OrganismName() const
{
	return "Human";
}

Human::~Human()
{
}
