#pragma once
#include "Strategy.h"
#include "BFS.h"

class Best : public Strategy
{
	BFS bfs;
public:
	Best() {};
	DIRECTION getNextDirection(Board& board, Ghost& ghost, Position pacmanPosition);
};
