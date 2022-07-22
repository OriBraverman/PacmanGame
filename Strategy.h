#pragma once
#include "Board.h"
#include "Ghost.h"

class Strategy
{
public:
	Strategy() {};
	virtual DIRECTION getNextDirection(Board& board, Ghost& ghost, Position pacmanPosition) = 0;
};
