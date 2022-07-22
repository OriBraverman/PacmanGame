#pragma once
#include "Board.h"
#include <vector>
#include <queue>
using std::vector;
using std::queue;

class BFS
{
	int posToIndex(Board& board, Position p);
public:
	BFS() {};
	Position reconstructPath(Board& board,const  Position& pacmanPos,const  Position& ghostPos, vector<Position*>fatherTree);
	vector<Position*> doBFS(Board& board, Position ghostPos);
};