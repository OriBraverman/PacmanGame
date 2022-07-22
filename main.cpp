#include <windows.h>
#include <iostream>
#include "PacmanGame.h"

int main(int argc, char *argv[]) 
{
	PacmanGame game;
	PLAY_MODE mode;
	try
	{
		mode = checkPlayMode(argc, argv);
		game.play(mode);
	}
	catch (int exception)
	{
		cout << "exception usage: " << argv[0] << "the correct input is -save/-load [-silent]" << endl;
	}
	
}

