#include "Pacman.h"

Pacman::Pacman() 
	: Creature(Position(), (char)FIGURES::PACMAN, (Color)FIGURES_COLORS::cPACMAN, DIRECTION::STAY) 
{
	userControls[0] = PACMAN_CONTROL[0];
	userControls[1] = PACMAN_CONTROL[1];
	userControls[2] = PACMAN_CONTROL[2];
	userControls[3] = PACMAN_CONTROL[3];
	userControls[4] = PACMAN_CONTROL[4];
}

Pacman::Pacman(Position position)
	: Creature(position,(char)FIGURES::PACMAN,(Color)FIGURES_COLORS::cPACMAN, DIRECTION::STAY)
{
	userControls[0] = PACMAN_CONTROL[0];
	userControls[1] = PACMAN_CONTROL[1];
	userControls[2] = PACMAN_CONTROL[2];
	userControls[3] = PACMAN_CONTROL[3];
	userControls[4] = PACMAN_CONTROL[4];
}

void Pacman::setDirection(char key)
{
	int dir = getDirectionByChar(key);
	if (dir != -1)
		direction = (DIRECTION)dir;
}

int Pacman::getDirectionByChar(char key)
{
	for (int i = 0; i < 5; i++)
	{
		if (toLower(userControls[i]) == toLower(key))
		{
			return i;
		}
	}
	return -1;
}


