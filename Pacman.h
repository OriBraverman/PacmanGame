#pragma once
#include "Creature.h"
#define PACMAN_CONTROL "ADWXS"
class Pacman : public Creature
{
	char userControls[5];
public:
	Pacman();
	Pacman(Position position);
	void setDirection(char direction);
	int getDirectionByChar(char key);
};


