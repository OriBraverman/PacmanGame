#pragma once
#include <iostream>
#include "Enum.h"

class Position
{
	int x, y;
public:
	Position();
	Position(int _x, int _y);
	int getX() const;
	int getY() const;
	void setX(int _x);
	void setY(int _y);
	void setPosition(int _x, int _y);
	void setPosition(const Position& other);
	bool equals(const Position& other)const;
	double distance(const Position& next)const;
	DIRECTION directionToOther(const Position& other)const;
};
