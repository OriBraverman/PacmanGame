#pragma once
#include "Strategy.h"

class Novice: public Strategy
{
	int& turnNumber;
public:
	Novice(int& _turnNumber) :turnNumber(_turnNumber) {};
	DIRECTION getNextDirection(Board& board, Ghost& ghost, Position pacmanPosition);
};
