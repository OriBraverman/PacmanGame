#include "Board.h"

Board::Board()
{
    logicalHeight = 0;
    logicalWidth = 0;
    for (int i = 0; i < WIDTH * HEIGHT + 1; i++)
        board[i] = ' ';
}

void Board::print(bool enableColor) const {
    for (int i = 0; i < logicalHeight; i++)
    {
        for (int j = 0; j < logicalWidth; j++)
        {
            if (enableColor)
            {
                if (board[i*WIDTH+j] == (char)FIGURES::WALL)
                    setTextColor((Color)FIGURES_COLORS::cWALL);
                else if (board[i * WIDTH + j] == (char)FIGURES::BREAD_CRUMBS)
                    setTextColor((Color)FIGURES_COLORS::cBREAD_CRUMBS);
            }
            if(i!= logicalHeight-1 || j!= logicalWidth-1)
                std::cout << board[i * WIDTH + j];
        }    
    }
}

char Board::get(int x, int y) const
{
    return board[WIDTH * y + x];
}

char Board::get(Position p) const
{
    return board[WIDTH * p.getY() + p.getX()];
}

void Board::set(int x, int y, char key)
{
    board[WIDTH * y + x] = key;
}

const Position& Board::getLegendStartingPoint() const
{
    return legendStartingPoint;
}

void Board::setLegendStartingPoint(int x, int y)
{
    legendStartingPoint.setX(x);
    legendStartingPoint.setY(y);
}

void Board::setPacmanInitials(int x, int y)
{
    pacman_initial.setX(x);
    pacman_initial.setY(y);
}

const Position& Board::getPacmanInitials() const
{
    return pacman_initial;
}

Position Board::getGhostsInitial(int ghostNum) const
{
    return ghosts_initial[ghostNum];
}

void Board::setGhostsInitial(int x, int y, int ghostNum)
{
    ghosts_initial[ghostNum].setX(x);
    ghosts_initial[ghostNum].setY(y);
}

const Position& Board::getOffset() const
{
    return offset;
}

void Board::setOffset(int x, int y)
{
    offset.setX(x);
    offset.setY(y);
}

void Board::set(const Position& p, char key)
{
    board[WIDTH * p.getY() + p.getX()] = key;
}

bool Board::isWall(int x, int y) const
{
    char val = get(x, y);
    return val == (char)FIGURES::WALL;
}

bool Board::isWall(Position p) const
{
    char val = get(p.getX(), p.getY());
    return val == (char)FIGURES::WALL;
}

Position Board::getNextPosition(Position current, DIRECTION direction, bool canPassTunnels)
{
    int x = current.getX(), y = current.getY();
    switch (direction)
    {
    case DIRECTION::UP:
        if (y > 0)
            y = y - 1;
        else if (canPassTunnels)
            y = logicalHeight - 1;
        break;
    case DIRECTION::DOWN:
        if (y < logicalHeight - 1)
            y = y + 1;
        else if (canPassTunnels)
            y = 0;
        break;
    case DIRECTION::LEFT:
        if (x > 0)
            x = x - 1;
        else if (canPassTunnels)
            x = logicalWidth - 2;
        break;
    case DIRECTION::RIGHT:
        if (x < logicalWidth - 2)  // last char is '/n'
            x = x + 1;
        else if (canPassTunnels)
            x = 0;
        break;
    default:
        break;
    }
    return Position(x, y);
}

bool Board::isContainsBreadcrumbs(Position position) const
{
    char val = get(position.getX(), position.getY());
    return val == (char)FIGURES::BREAD_CRUMBS;
}

Position Board::getLivesPosition()
{
    return Position(offset.getX()+OFFSET::LIVES_X, offset.getY() + OFFSET::LIVES_Y);
}

Position Board::getScorePosition()
{
    return Position(offset.getX() + OFFSET::SCORE_X, offset.getY() + OFFSET::SCORE_Y);
}

int Board::getLogicalWidth() const
{
    return logicalWidth;
}

int Board::getLogicalHeight() const
{
    return logicalHeight;
}

void Board::setLogicalWidth(int _logicalWidth)
{
    logicalWidth = _logicalWidth;
}

void Board::setLogicalHeight(int _logicalHeight)
{
    logicalHeight = _logicalHeight;
}

void Board::printLegend()
{
    gotoxy(offset.getX(), offset.getY());
    cout << "   The lives:       ";
    gotoxy(offset.getX(), offset.getY()+1);
    cout << "   The score:       ";
    gotoxy(offset.getX(), offset.getY() + 2);
    cout << "-Press Esc to pause-";
}

bool Board::isInLegend(Position p)
{
    // TODO check consts
    int px = p.getX(), py = p.getY();
    int lx = legendStartingPoint.getX(), ly = legendStartingPoint.getY();
    return px >= lx && px < lx + 20 && py >= ly && py < ly + 3;
}

Position Board::getRandomFreePosition()
{
    Position res;
    char valInPosition;
    res.setX(rand() % logicalWidth);
    res.setY(rand() % logicalHeight);
    valInPosition = get(res);
    while (valInPosition == (char)FIGURES::WALL || isInLegend(res))
    {
        res.setX(rand() % logicalWidth);
        res.setY(rand() % logicalHeight);
        valInPosition = get(res);
    }
    return res;
}