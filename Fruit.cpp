#include "Fruit.h"

Fruit::Fruit()
{
	displayed = false;
	nextTimeAppear = -1;
	timeToDisappear = -1;
}

bool Fruit::getDisplayed()
{
	return displayed;
}
void Fruit::setDisplayed(bool _displayed)
{
	displayed = _displayed;
}
int Fruit::getNextTimeAppear()
{
	return nextTimeAppear;
}
void Fruit::setNextTimeAppear(int _nextTimeAppear)
{
	nextTimeAppear = _nextTimeAppear;
}

int Fruit::getValue()
{
	return appearance - '0';
}

int Fruit::getTimeToDisappear()
{
	return timeToDisappear;
}
void Fruit::setTimeToDisappear(int time)
{
	timeToDisappear = time;
}