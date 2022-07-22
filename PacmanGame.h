#pragma once
#include "Utilities.h"
#include "Ghost.h"
#include "Pacman.h"
#include "Board.h"
#include "Menu.h"
#include "Fruit.h"
#include "Strategy.h"
#include "Best.h"
#include "Good.h"
#include "Novice.h"
#include <string>
#include <filesystem>
namespace fs = std::filesystem;
using std::string;
using std::fstream;
using std::ios;

class PacmanGame
{
	enum KEYS { ESC = 27 };
	enum OPTIONS { INITIAL_LIVES = 3, GHOST_SPEED = 2, FRUIT_SPEED = 10, GAME_SPEED = 100, MIN_FRUIT_DISAPPEARENCE = 50, MIN_FRUIT_APPEARENCE = 100, FRUIT_OFFSET = 20 };
	enum LEVEL { BEST = 'a', GOOD = 'b', NOVICE = 'c' };
	enum STEPS_CHANGES {PACMAN, GHOST0, GHOST1, GHOST2, GHOST3, FRUIT, FRUIT_APPEAR, FRUIT_DISAPPEAR, STEPS_SIZE};
	enum RESULT_CHANGES {PACMAN_DIED, FINISHED_SCREEN, RESULT_SIZE};
	int breadCrumbs = 0, score, lives;
	bool enableColor;
	bool allFilesGame;
	string currFileName;
	int ghostsTurnNumber = 0;
	int gameNumber = 0;
	int currBoard = 0;
	vector<string> fileNames;
	PLAY_MODE playMode;
	Board board;
	Pacman pacman;
	vector<Ghost> ghosts;
	Fruit fruit;
	Menu menu;
	Strategy* strategy;
public:
	PacmanGame();
	PacmanGame(const PacmanGame& other)=delete;
	~PacmanGame() { delete strategy; }
	void play(PLAY_MODE mode);
private:
	const PacmanGame& operator =(const const PacmanGame& other) = delete;  
	void playNormal();
	void updateStepsFile(fstream &steps_file, int pacmanSteps, bool* steps_changes);
	void updateResultFile(fstream &result_file, int pacmanSteps, bool* result_changes);
	bool resultComparison(bool* result_changes_game, bool* result_changes_file);
	void load();
	bool runLoad();
	void setLineToGame(fstream& steps_file);
	void setCreatureToGame(fstream& steps_file);
	bool initBoardFromFile(string fileName);
	bool updateLineToGame(string line, int currHeight, int &pacmanCounter, int &legendCounter);
	void updateLineToResult(fstream& result_file, bool* result_changes_file);
	void run();
	void startGame();
	void executeChoice(char userChoice);
	void chooseLevel();
	static bool isValidOption(char userChoice);
	static bool isValidLevel(char userChoice);
	static bool isValidLoadMethod(char userChoice);
	void changeColor(char apperance);
	void displayByApperance(Position p, char apperance);
	bool checkGhostCollisions(Position& newPosition);
	void readBoardsNames();
	void winCheck(bool* result_changes);
	void moveFruit(bool *steps_changes);
	void movePacman(bool *result_changes);
	void moveGhosts(bool* steps_changes, bool* result_changes);
	void printLives();
	void printScore();
	void setInitialPositions(bool reset);
	void actOnGhostCollision(bool* result_changes);
	void initFruit();
	bool checkFruitCollision(Position p);
	void removeFruit();
	void setStrategy(LEVEL level);
	void chooseLoadMethod();
	char getUserChoice(void (*print) (), bool (*isValid) (char));
};
