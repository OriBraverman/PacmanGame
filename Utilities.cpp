#include "Utilities.h"
#define EXCEPTION -10

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout << flush;
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

void setTextColor(Color colorToSet) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)colorToSet);
}

void hideCursor()
{
	HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CURSOR;
	CURSOR.dwSize = 1;
	CURSOR.bVisible = FALSE;
	SetConsoleCursorInfo(myconsole, &CURSOR);//second argument need pointer
}

void clear_screen()
{
	system("cls");
}

char toLower(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return 'a' + (c - 'A');
	}
	return c;
}

//the function taken from https://www.geeksforgeeks.org/sort-file-names-in-lexicographical-order-of-their-extensions/
// Comparator function to sort an array of strings
// based on the extension of their file names
bool custom(string s1, string s2)
{

	// Stores index of '.' in s1
	size_t i = s1.find('.');

	// Stores index of '.' in s2
	size_t j = s2.find('.');

	// Stores name of extension of s2
	string d = s1.substr(i + 1);

	// Stores name of extension of s2
	string e = s2.substr(j + 1);

	// If both files have the
	// same extension name
	if (d == e) {

		// Return lexicographically
		// smaller of the two strings
		return s1 < s2;
	}

	return d < e;
}

PLAY_MODE checkPlayMode(int argc, char* argv[])
{
	if (argc == 1)
	{
		return PLAY_MODE::NORMAL;
	}
	else if ((argc == 2 || (argc == 3 && strcmp(argv[2], "-silent") == 0)) && strcmp(argv[1], "-save") == 0)
	{
		return PLAY_MODE::SAVE;
	}
	else if (argc == 2 && strcmp(argv[1], "-load") == 0)
	{
		return PLAY_MODE::LOAD;
	}
	else if (argc == 3 && strcmp(argv[1], "-load") == 0 && strcmp(argv[2], "-silent") == 0)
	{
		return PLAY_MODE::LOAD_SILENT;
	}
	else
	{
		throw EXCEPTION;
	}
}