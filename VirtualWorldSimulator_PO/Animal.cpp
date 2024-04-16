#include "Animal.h"
#include "MyFunctions.h"
#include <iostream>

enum Direction
{
	N,
	//NE,
	E,
	//SE,
	S,
	//SW,
	W,
	//NW
};

Animal::Animal(World& world) : Organism(world)
{
}

void Animal::Action()
{
	SetTextColour(8);//127
	//Gotoxy(2 * xPos - 1, yPos + 2);
	Organism::Print();
	if ((xPos % 2 == 0 && yPos % 2 == 1) || (xPos % 2 == 1 && yPos % 2 == 0))
	{
		std::cout << (char)176 << (char)176;
	}
	else
	{
		std::cout << "  ";
	}

	Direction direction = Direction(rand() % 4);
	switch (direction)
	{
	case N:
		if (yPos == 1) yPos++;
		else yPos--;
		break;/*
	case NE:
		if (yPos == 1) yPos++;
		else yPos--;
		if (xPos == world.GetWidth()) xPos--;
		else xPos++;
		break;*/
	case E:
		if (xPos == world.GetWidth()) xPos--;
		else xPos++;
		break;/*
	case SE:
		if (xPos == world.GetWidth()) xPos--;
		else xPos++;
		if (yPos == world.GetHeight()) yPos--;
		else yPos++;
		break;*/
	case S:
		if (yPos == world.GetHeight()) yPos--;
		else yPos++;
		break;/*
	case SW:
		if (yPos == world.GetHeight()) yPos--;
		else yPos++;
		if (xPos == 1) xPos++;
		else xPos--;
		break;*/
	case W:
		if (xPos == 1) xPos++;
		else xPos--;
		break;/*
	case NW:
		if (xPos == 1) xPos++;
		else xPos--;
		if (yPos == 1) yPos++;
		else yPos--;
		break;*/
	default:
		break;
	}
}

void Animal::Collision()
{
}

void Animal::Print()
{
	//SetTextColour(207);//196
}

/*
Animal::~Animal()
{
}
*/