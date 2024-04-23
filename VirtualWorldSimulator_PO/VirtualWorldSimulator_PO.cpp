#include <iostream>
#include <conio.h>
#include <vector>
#include "MyFunctions.h"
#include <fstream>

#include "UserInterface.h"
#include "World.h"
#include "Organism.h"

#include "Human.h"
#include "Antelope.h"
#include "Fox.h"
#include "Sheep.h"
#include "Tortoise.h"
#include "Wolf.h"

#include "DeadlyNightshade.h"
#include "Grass.h"
#include "Guarana.h"
#include "Sonchus.h"
#include "SosnowskysHogweed.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::fstream;

int main()
{
	setlocale(LC_ALL, "en_US.UNICODE");
	srand((unsigned)time(nullptr));
	SetTextColour(15);
	const char* name = "Pawel";
	const char* surname = "Kurpiewski";
	const char* studentsNumber = "198203";
	World* world{};

	const char* options[] = { "Create new random world", "Load world from save", "Quit game"};
	int pos = 0;
	bool end = false;
	int x = 0;
	int y = 0;
	while (!end)
	{ // 224 72 , 224 80
		Gotoxy(0, 1);
		SetTextColour(15);
		cout << "Virtual World Simulator\nProject no 1 for the \"Object Programming\" laboratories\nPawel Kurpiewski 198203";
		switch (x)
		{
		case 224:
			y = _getch();
			if (y == 72 && pos != 0)
			{
				pos--;
			}
			else if (y == 80 && pos != sizeof(options) / sizeof(options[0]) - 1)
			{
				pos++;
			}
			break;
		case '\r':
			end = true;
			switch (pos)
			{
			case 0:
				int width, height;
				cout << "\n\nboard width (min. 5): ";
				cin >> width;
				if (width < 5)
				{
					width = 5;
					cout << "set width to 5\n";
				}
				cout << "board height (min 5): ";
				cin >> height;
				if (height < 5)
				{
					height = 5;
					cout << "set height to 5\n";
				}
				world = new World(width, height);
				break;
			case 1:
				fstream* file;
				file = new fstream("SAVE.txt", std::ios::in);
				world = new World(file);
				delete file;
				break;
			case 2:
				return 0;
				break;
			default:
				break;
			}
		}

		for (int i = 0; i < sizeof(options) / sizeof(options[0]); i++)
		{
			Gotoxy(10, 10 + i);
			SetTextColour(pos == i ? 112 : 15);
			printf(options[i]);
		}
		if (!end)
		{
			x = _getch();
		}
		else
		{
			system("cls");
		}
	}

	UserInterface ui(name, surname, studentsNumber, *world);
	int xx = 1;
	while (xx)
	{
		ui.Print();
		xx = world->MakeTurn();
		SetTextColour(160);
		cout << "END OF TURN! Press enter to continue.";
		world->logs.clear();
		SetTextColour(15);

		int input = 0;
		do
		{
			if (input == 27)
			{
				return 0;
			}
			input = _getch();
		} while (input != 13);
		system("cls");
	}
	delete world;
	return 0;
}