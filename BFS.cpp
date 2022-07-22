#include "BFS.h"

int BFS::posToIndex(Board& board, Position p)
{
	return (board.getLogicalWidth() - 1) * p.getY() + p.getX();
}

Position BFS::reconstructPath(Board& board, const Position& pacmanPos, const Position& ghostPos, vector<Position*>fatherTree)
{
	Position ghostNextPos;
	Position* curr = fatherTree[posToIndex(board, pacmanPos)];
	Position* nextCurr = nullptr;
	if (fatherTree[posToIndex(board, pacmanPos)]->equals(ghostPos))
		return pacmanPos;
	if (curr != nullptr && fatherTree[posToIndex(board, *curr)] != nullptr)
	{
		nextCurr = fatherTree[posToIndex(board, *curr)];
		while (fatherTree[posToIndex(board, *nextCurr)] != nullptr)
		{
			curr = nextCurr;
			nextCurr = fatherTree[posToIndex(board, *nextCurr)];
		}
	}
	if (curr != nullptr && fatherTree[posToIndex(board, *curr)]->equals(ghostPos))
	{
		ghostNextPos = Position(*curr);
	}
	for (int i = 0; i < fatherTree.size(); i++)
	{
		if (fatherTree[i] != nullptr)
			delete fatherTree[i];
	}
	return ghostNextPos;
}

vector<Position*> BFS::doBFS(Board& board, Position ghostPos)
{
	queue<Position> toCheck;
	vector<bool> visited;
	vector<Position*> fatherTree;
	int startPos, nextPos;
	int totalCells = (board.getLogicalWidth() - 1) * board.getLogicalHeight();
	visited.reserve(totalCells);
	fatherTree.reserve(totalCells);
	for (int i = 0; i < totalCells; i++)
	{
		visited.push_back(false);
		fatherTree.push_back(nullptr);

	}
	startPos = (board.getLogicalWidth() - 1) * ghostPos.getY() + ghostPos.getX();
	visited[startPos] = true;
	toCheck.push(ghostPos);
	while (!toCheck.empty())
	{
		Position toProsses = toCheck.front();
		toCheck.pop();
		for (int i = 0; i < 4; i++)
		{
			Position ghostNextMove = board.getNextPosition(toProsses, (DIRECTION)i, false);
			nextPos = (board.getLogicalWidth() - 1) * ghostNextMove.getY() + ghostNextMove.getX();
			if (board.isWall(ghostNextMove) == false && !visited[nextPos])
			{
				toCheck.push(ghostNextMove);
				visited[nextPos] = true;
				fatherTree[nextPos] = new Position(toProsses);
			}
		}
	}
	return fatherTree;
}