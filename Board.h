#pragma once
#include "Utilities.h"
#include "Position.h"
#include "Enum.h"

class Board
{
public:
	enum OFFSET { SCORE_X = 15, SCORE_Y = 1, LIVES_X = 15, LIVES_Y = 0 };
	enum DIMENSIONS { WIDTH = 81, HEIGHT = 25 };
private:
	int logicalWidth;
	int logicalHeight;
	Position legendStartingPoint;
	Position pacman_initial;
	Position ghosts_initial[4];
	Position offset;
	char board[WIDTH * HEIGHT + 1];
public:
	Board();
	char get(int x, int y) const;
	char get(Position p) const;
	void set(int x, int y, char key);
	const Position& getLegendStartingPoint()const;
	void setLegendStartingPoint(int x, int y);
	const Position& getPacmanInitials()const;
	void setPacmanInitials(int x, int y);
	Position getGhostsInitial(int ghostNum)const;
	void setGhostsInitial(int x, int y, int ghostNum);
	const Position& getOffset()const;
	void setOffset(int x, int y);
	void set(const Position& p, char key);
	void print(bool enableColor) const;
	bool isWall(int x, int y) const;
	bool isWall(Position p) const;
	bool isContainsBreadcrumbs(Position position) const;
	Position getNextPosition(Position current, DIRECTION direction, bool canPassWalls);
	Position getLivesPosition();
	Position getScorePosition();
	int getLogicalWidth()const;
	int getLogicalHeight()const;
	void setLogicalWidth(int logicalWidth);
	void setLogicalHeight(int logicalHeight);
	void printLegend();
	bool isInLegend(Position p);
	Position getRandomFreePosition();
};
