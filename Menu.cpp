#include "Menu.h"

Menu::Menu(){}

void Menu::print()
{
	setTextColor(Color::WHITE);
	cout << endl << "-GAME MENU-" << endl;
	cout << "(1) Start a new game with color support" << endl
		 << "(2) Start a new game without color support" << endl
		 << "(8) Present instructions and keys" << endl
		 << "(9) EXIT" << endl;
}


void Menu::printInstructions()
{
	setTextColor(Color::WHITE);
	cout << "To play the pacman game you have to eat all the breadcrumbs without getting caught by the ghosts :)" << endl;
	cout << "To go LEFT enter a or A" << endl
		 << "To go RIGHT enter d or D" << endl
		 << "To go UP enter w or W" << endl
		 << "To go Down enter x or X" << endl
		 << "To STAY enter s or S" << endl;
}

void Menu::printLevels()
{
	cout << "\nChoose level:" << endl
		 << "(a) BEST" << endl
		 << "(b) GOOD" << endl
		 << "(c) NOVICE" << endl;
}

void Menu::printGameLoadMethod()
{
	cout << "\nChoose game load method:\n";
	cout << "(a) load by fileName" << endl;
	cout << "(b) load all files" << endl;
}