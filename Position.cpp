#include "Position.h"

Position::Position() {
	x = y = 0;
}

Position::Position(int _x, int _y) {
	x = _x;
	y = _y;
}

//Position::Position(Position& other)
//{
//	x = other.x;
//	y = other.y;
//}
bool Position::equals(const Position& other)const
{
	return other.x == x && other.y == y;
}

double Position::distance(const Position& other) const
{
	return sqrt(pow((x - other.getX()), 2) + pow((y - other.getY()), 2));
}

DIRECTION Position::directionToOther(const Position& next) const
{
	if (this->distance(next) == 1)//the positions are adjast
	{
		if (next.getX() > x)
			return DIRECTION::RIGHT;
		else if(next.getX() < x)
			return DIRECTION::LEFT;
		else if (next.getY() < y)
			return DIRECTION::UP;
		else if (next.getY() > y)
			return DIRECTION::DOWN;
	}
	return DIRECTION::STAY;
}

int Position::getX() const
{
	return x;
}
int Position::getY() const
{
	return y;
}
void Position::setX(int _x)
{
	x = _x;
}
void Position::setY(int _y)
{
	y = _y;
}

void Position::setPosition(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Position::setPosition(const Position& other)
{
	x = other.getX();
	y = other.getY();
}