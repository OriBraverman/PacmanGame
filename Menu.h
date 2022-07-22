#pragma once
#include <iostream>
#include "Utilities.h"
using std::cout;
using std::endl;

class Menu
{
public:
	enum OPTIONS { START_GAME_WITH_COLORS = '1', START_GAME_WITHOUT_COLORS = '2', PRESENT_KEYS = '8', EXIT = '9'
	, LOAD_BY_NAME = 'a', LOAD_ALL_FILES = 'b'};
	Menu();
	static void print();
	void printInstructions();
	static void printLevels();
	static void printGameLoadMethod();

};
