#pragma once
#include "Creature.h"

class Fruit : public Creature
{
	bool displayed;
	int nextTimeAppear;
	int timeToDisappear;
public:
	Fruit();
	bool getDisplayed();
	int getNextTimeAppear();
	void setDisplayed(bool _displayed);
	void setNextTimeAppear(int _nextTimeAppear);
	int getValue();
	int getTimeToDisappear();
	void setTimeToDisappear(int time);
};