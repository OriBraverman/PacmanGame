#include "Ghost.h"

Ghost::Ghost() :Creature(Position(), (char)FIGURES::GHOST, (Color)FIGURES_COLORS::cGHOST) {}

Ghost::Ghost(Position position)
	:Creature(position,(char)FIGURES::GHOST,(Color)FIGURES_COLORS::cGHOST)
{}