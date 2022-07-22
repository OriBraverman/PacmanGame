#include "Good.h"

Good::Good(int& _turnNumber):turnNumber(_turnNumber)
{
	lastTurnForDirection = -1;
}

DIRECTION Good::getNextDirection(Board& board, Ghost& ghost, Position pacmanPosition)
{
	if (turnNumber <= lastTurnForDirection)
		return ghost.getDirection();
	else if (rand() % 20 == 0)
	{
		lastTurnForDirection = turnNumber + 5;
		return (DIRECTION)(rand() % 4);
	}
	// otherwise run BFS
	vector<Position*>fatherTree = bfs.doBFS(board, ghost.getPosition());
	Position p = bfs.reconstructPath(board, pacmanPosition, ghost.getPosition(), fatherTree);
	return ghost.getPosition().directionToOther(p);
}