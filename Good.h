#pragma once
#include "Strategy.h"
#include "BFS.h"
class Good : public Strategy
{
	int& turnNumber;
	int lastTurnForDirection;
	BFS bfs;
public:
	Good(int& _turnNumber);
	DIRECTION getNextDirection(Board& board, Ghost& ghost, Position pacmanPosition);

};
