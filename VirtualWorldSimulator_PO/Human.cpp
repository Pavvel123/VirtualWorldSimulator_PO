#include "Human.h"
#include <iostream>
#include "MyFunctions.h"
#include <conio.h>

Human::Human(int xPos, int yPos, World& world)
	: Animal(world)
{
	Organism::strength = 5;
	Organism::initiative = 4;
	Organism::xPos = xPos;
	Organism::yPos = yPos;
	Organism::world = world;
}

void Human::Action()
{ // 49 - 57
	// N - 224 72
	// S - 224 80
	// E - 224 77
	// W - 224 75
	int input = _getch();
	while (input != 224)
	{
		input = _getch();
	}
	int input2 = _getch();
	SetTextColour(8);//127
	Gotoxy(2 * xPos - 1, yPos + 2);
	if ((xPos % 2 == 0 && yPos % 2 == 1) || (xPos % 2 == 1 && yPos % 2 == 0))
	{
		std::cout << (char)176 << (char)176;
	}
	else
	{
		std::cout << "  ";
	}

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

void Human::Collision()
{
}

void Human::Print()
{
	Organism::Print();
	SetTextColour(148);//159
	std::cout << "HU";
}

Human::~Human()
{
}
