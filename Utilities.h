#pragma once

#include "Enum.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::flush;
using std::string;

void gotoxy(int x, int y);
void setTextColor(Color);
void clear_screen();
void hideCursor();
char toLower(char c);
bool custom(string s1, string s2);
PLAY_MODE checkPlayMode(int argc, char* argv[]);
