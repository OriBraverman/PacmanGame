#pragma once
#include <iostream>

enum class Color
{
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHTGREY = 7,
	DARKGREY = 8,
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,
	WHITE = 15
};

enum class DIRECTION { 
	LEFT = 0, 
	RIGHT = 1, 
	UP = 2, 
	DOWN = 3, 
	STAY = 4 
};

enum class FILE_FIGURES {
	GHOST = '$',
	PACMAN = '@',
	BREAD_CRUMBS = ' ',
	WALL = '#',
	NOTHING = '%',
	LEGEND = '&'
};

enum class FIGURES {
	GHOST = '$',
	PACMAN = '@',
	BREAD_CRUMBS = '*',
	WALL = '#',
	FRUIT_5 = '5',
	FRUIT_6 = '6',
	FRUIT_7 = '7',
	FRUIT_8 = '8',
	FRUIT_9 = '9'
};

enum class FIGURES_COLORS {
	cGHOST = (int)Color::GREEN,
	cPACMAN = (int)Color::YELLOW,
	cBREAD_CRUMBS = (int)Color::BROWN,
	cWALL = (int)Color::WHITE,
	cFRUIT = (int)Color::LIGHTCYAN
};

enum class PLAY_MODE { 
	NORMAL=0, 
	SAVE=1, 
	LOAD=2, 
	LOAD_SILENT=3 
};