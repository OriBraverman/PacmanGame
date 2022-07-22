#include "Novice.h"


DIRECTION Novice::getNextDirection(Board& board, Ghost& ghost, Position pacmanPosition)
{
	if (turnNumber % 20 == 0)
		return (DIRECTION)(rand() % 4);
	else
		return ghost.getDirection();
}