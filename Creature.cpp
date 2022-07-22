#include "Creature.h"

Creature::Creature()
	:position(),direction(DIRECTION::RIGHT),appearance('?'),color(Color::WHITE)
{}

Creature::Creature(Position position, char appearance, Color color, DIRECTION direction)
	:position(position), appearance(appearance), color(color), direction(direction) {}

const Position& Creature::getPosition()
{
	return position;
}

char Creature::getAppearance()
{
	return appearance;
}

void Creature::setDirection(DIRECTION _direction)
{
	direction = _direction;
}

void Creature::setPosition(const Position& p)
{
	position.setPosition(p);
}

void Creature::setPosition(int x, int y)
{
	position.setPosition(x, y);
}

void Creature::setAppearance(char _appearance)
{
	appearance = _appearance;
}

DIRECTION Creature::getDirection()
{
	return direction;
}

void Creature::print()
{
	setTextColor(color);
	cout << appearance;
}

Color Creature::getColor()
{
	return color;
}
