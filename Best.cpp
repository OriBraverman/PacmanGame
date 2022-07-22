#include "Best.h"

DIRECTION Best::getNextDirection(Board& board, Ghost& ghost, Position pacmanPosition)
{
	vector<Position*>fatherTree = bfs.doBFS(board, ghost.getPosition());
	Position p = bfs.reconstructPath(board, pacmanPosition, ghost.getPosition(), fatherTree);
	return ghost.getPosition().directionToOther(p);
}


