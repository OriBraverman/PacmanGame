#pragma once
#include "Position.h"
#include "Enum.h"
#include "Utilities.h"
#include <iostream>
using std::ostream;

class Creature
{
protected:
	Position position;
	char appearance;
	DIRECTION direction;
	Color color;
public:
	Creature();
	Creature(Position position, char appearance, Color color=Color::WHITE, DIRECTION direction = DIRECTION::RIGHT);
	void print();
	//friend ostream& operator<<(ostream& os, const Creature& other);//deside later
	const Position& getPosition();
	char getAppearance();
	Color getColor();
	DIRECTION getDirection();
	void setDirection(DIRECTION _direction);
	void setPosition(int x, int y); //maybe to delete
	void setPosition(const Position& p);
	void setAppearance(char appearance);
};