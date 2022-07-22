#include "PacmanGame.h"

PacmanGame::PacmanGame()
{
	strategy = nullptr;
	readBoardsNames();
	lives = OPTIONS::INITIAL_LIVES;
}

char PacmanGame::getUserChoice(void (*print) (), bool (*isValid) (char))
{
	char userChoice;
	print();
	cin >> userChoice;
	while (!isValid(userChoice))
	{
		clear_screen();
		cout << "Your choice is not valid, please choose again" << endl;
		print();
		cin >> userChoice;
	}
	clear_screen();
	return userChoice;
}

void PacmanGame::updateStepsFile(fstream& steps_file, int pacmanSteps, bool* steps_changes)
{
	bool change = false;
	for (int i = 0; i < STEPS_CHANGES::STEPS_SIZE; i++)
		if (steps_changes[i] == true)
			change = true;
	if (change)
	{
		steps_file << pacmanSteps << " ";
		for (int i = 0; i < STEPS_CHANGES::STEPS_SIZE; i++)
		{
			if (steps_changes[i] == true)
			{
				switch (i)
				{
				case STEPS_CHANGES::PACMAN:
					steps_file << STEPS_CHANGES::PACMAN<<" "<<(int)pacman.getDirection()<<" ";
					break;
				case STEPS_CHANGES::GHOST0:
					steps_file << STEPS_CHANGES::GHOST0 << " " << (int)ghosts[0].getDirection()<<" ";
					break;
				case STEPS_CHANGES::GHOST1:
					steps_file << STEPS_CHANGES::GHOST1 << " " << (int)ghosts[1].getDirection() << " ";
					break;
				case STEPS_CHANGES::GHOST2:
					steps_file << STEPS_CHANGES::GHOST2 << " " << (int)ghosts[2].getDirection() << " ";
					break;
				case STEPS_CHANGES::GHOST3:
					steps_file << STEPS_CHANGES::GHOST3 << " " << (int)ghosts[3].getDirection() << " ";
					break;
				case STEPS_CHANGES::FRUIT:
					steps_file << STEPS_CHANGES::FRUIT << " " << (int)fruit.getDirection() << " ";
					break;
				case STEPS_CHANGES::FRUIT_APPEAR:
					steps_file << STEPS_CHANGES::FRUIT_APPEAR << " " << fruit.getPosition().getX()
						<< " " << fruit.getPosition().getY() << " " << fruit.getAppearance() << " "
						<< (int)fruit.getDirection() << " ";
					break;
				case STEPS_CHANGES::FRUIT_DISAPPEAR:
					steps_file << STEPS_CHANGES::FRUIT_DISAPPEAR << " ";
					break;
				default:
					break;
				}
			}
		}
		steps_file << endl;
	}
}
void PacmanGame::updateResultFile(fstream& result_file, int pacmanSteps, bool* result_changes)
{
	bool change = false;
	for (int i = 0; i < RESULT_CHANGES::RESULT_SIZE; i++)
		if (result_changes[i] == true)
			change = true;
	if (change)
	{
		result_file << pacmanSteps << " ";
		for (int i = 0; i < RESULT_CHANGES::RESULT_SIZE; i++)
		{
			if (result_changes[i] == true)
			{
				switch (i)
				{
				case RESULT_CHANGES::PACMAN_DIED:
					result_file << RESULT_CHANGES::PACMAN_DIED << " ";
					break;
				case RESULT_CHANGES::FINISHED_SCREEN:
					result_file << RESULT_CHANGES::FINISHED_SCREEN << " ";
					break;
				default:
					break;
				}
			}
		}
		result_file << endl;
	}
}

void PacmanGame::play(PLAY_MODE mode)
{
	playMode = mode;//update data member
	switch (playMode)
	{
	case PLAY_MODE::NORMAL:
		playNormal();
		break;
	case PLAY_MODE::SAVE:
		playNormal();
		break;
	case PLAY_MODE::LOAD:
		load();
		break;
	case PLAY_MODE::LOAD_SILENT:
		load();
		break;
	default:
		break;
	}
}

void PacmanGame::load()
{
	enableColor = true;
	allFilesGame = true;
	startGame();
}

void PacmanGame::playNormal()
{
	char userChoice;
	userChoice = getUserChoice(Menu::print, isValidOption);
	while (userChoice != Menu::OPTIONS::EXIT)
	{
		executeChoice(userChoice);
		userChoice = getUserChoice(Menu::print, isValidOption);
		clear_screen();
	}
	executeChoice(userChoice);
}

void PacmanGame::executeChoice(char userChoice)
{
	switch (userChoice)
	{
	case Menu::OPTIONS::START_GAME_WITH_COLORS:
		enableColor = true;
		chooseLevel();
		chooseLoadMethod();
		startGame();
		break;
	case Menu::OPTIONS::START_GAME_WITHOUT_COLORS:
		enableColor = false;
		chooseLevel();
		chooseLoadMethod();
		startGame();
		break;
	case Menu::OPTIONS::PRESENT_KEYS:
		menu.printInstructions();
		break;
	case Menu::OPTIONS::EXIT:
		setTextColor(Color::WHITE);
		cout << "the game ended" << endl;
		break;
	default:
		break;
	}
}

void PacmanGame::chooseLevel()
{
	char userChoice = getUserChoice(Menu::printLevels, isValidLevel);
	setStrategy((LEVEL)userChoice);
}

void PacmanGame::setStrategy(LEVEL level)
{
	if (strategy != nullptr)
		delete strategy;
	switch (level)
	{
	case LEVEL::BEST:
	{
		strategy = new Best();
		break;
	}
	case LEVEL::GOOD:
	{
		strategy = new Good(ghostsTurnNumber);
		break;
	}
	case LEVEL::NOVICE:
	{
		strategy = new Novice(ghostsTurnNumber);
		break;
	}
	}
}

void PacmanGame::chooseLoadMethod()
{
	string fileName;
	char userChoice = getUserChoice(Menu::printGameLoadMethod, isValidLoadMethod);
	if (userChoice == Menu::OPTIONS::LOAD_BY_NAME)
	{
		cout << "Please enter a file with ending of .screen to load" << endl;
		cin >> fileName;
		clear_screen();
		currFileName = fileName;
		allFilesGame = false;
	}
	else
	{
		allFilesGame = true;
	}
}

void PacmanGame::startGame()
{
	bool succeed = true, succeedLoad=true;
	if (fileNames.size() == 0)
		cout << "ERROR: There is no board to load";
	else
	{
		breadCrumbs = 0;
		score = 0;
		ghostsTurnNumber = 0;
		lives = OPTIONS::INITIAL_LIVES;
		if (!allFilesGame)
		{
			succeed = initBoardFromFile(currFileName);
			if (succeed)
				run();
		}
		else //all files game
		{
			for (int i = 0; i < fileNames.size() && lives > 0; i++, gameNumber++)
			{
				clear_screen();
				succeed = initBoardFromFile(fileNames[i]);
				if (succeed)
				{
					if (playMode == PLAY_MODE::LOAD || playMode == PLAY_MODE::LOAD_SILENT)
					{
						if (!runLoad())
							succeedLoad = false;
					}
					else
						run();
				}
			}
			if (playMode == PLAY_MODE::LOAD_SILENT)
			{
				if (succeedLoad)
				{
					if (enableColor)
						setTextColor(Color::GREEN);
					cout << "The load succeeded";
				}
					
				else
				{
					if (enableColor)
						setTextColor(Color::RED);
					cout << "The load didn't succeed";
				}
			}
		}
	}
}

void PacmanGame::setInitialPositions(bool reset)
{
	if (reset)
	{
		displayByApperance(pacman.getPosition(), board.get(pacman.getPosition()));
		displayByApperance(board.getPacmanInitials(), pacman.getAppearance());

		for (int i = 0; i < ghosts.size(); i++) {
			displayByApperance(ghosts[i].getPosition(), board.get(ghosts[i].getPosition()));
			displayByApperance(board.getGhostsInitial(i), ghosts[i].getAppearance());

		}
	}
	pacman.setPosition(board.getPacmanInitials());

	for (int i = 0; i < ghosts.size(); i++)
		ghosts[i].setPosition(board.getGhostsInitial(i));
}

bool PacmanGame::initBoardFromFile(string fileName)
{
	int currHeight = 0, pacmanCounter = 0, legendCounter = 0;
	bool succeed = true;
	string line;
	ghosts.clear(); //init ghosts
	fstream boardFile(fileName, ios::in);
	if (!boardFile)
	{
		cout << "File could not be opened!" << endl;
		return false;
	}
	std::getline(boardFile, line);
	int lineLength = static_cast<int>(line.length());
	int logicalWidth = lineLength + 1; // +1 for the '\n'
	//the first line detrmine board logical size
	if (lineLength >= Board::DIMENSIONS::WIDTH || line.length() < 20)
	{
		cout << "ERROR: Board couldn't loaded: Board Width is not valid!" << endl;
		return false;
	}
	board.setLogicalWidth(logicalWidth);
	succeed = updateLineToGame(line, currHeight, pacmanCounter, legendCounter);
	if (!succeed)
		return succeed;
	currHeight++;
	while (!cin.eof() && currHeight < Board::DIMENSIONS::HEIGHT && line.length() >= lineLength)
	{
		line.clear();
		std::getline(boardFile, line);
		if (line.length() >= lineLength)
		{
			succeed = updateLineToGame(line, currHeight, pacmanCounter, legendCounter);
			if (!succeed)
				return succeed;
			currHeight++;
		}
	}
	if (!cin.eof() && currHeight > Board::DIMENSIONS::HEIGHT)
	{
		cout << "ERROR: Board couldn't loaded: There are too many lines on the file";
		return false;
	}
	board.setLogicalHeight(currHeight);

	//error if there is no pacman or no legend
	if (pacmanCounter == 0)
	{
		cout << "ERROR: Board couldn't loaded:  There are no pacman on this board";
		return false;
	}
	if (legendCounter == 0)
	{
		cout << "ERROR: Board couldn't loaded:  There are no legend on this board";
		return false;
	}

	// display the board
	if (playMode != PLAY_MODE::LOAD_SILENT)
	{
		board.print(enableColor);
		board.printLegend();
		printLives();
		printScore();
	}

	// display pacman and ghosts
	displayByApperance(pacman.getPosition(), board.get(pacman.getPosition()));
	for (int i = 0; i < ghosts.size(); i++) {
		displayByApperance(ghosts[i].getPosition(), board.get(ghosts[i].getPosition()));
	}
	// display fruit
	initFruit();
	displayByApperance(fruit.getPosition(), board.get(fruit.getPosition()));
	return succeed;
}

void PacmanGame::initFruit()
{
	Position fruitRandPos = board.getRandomFreePosition();
	fruit.setPosition(fruitRandPos);
	fruit.setNextTimeAppear(0);
	fruit.setDisplayed(true);
	fruit.setDirection((DIRECTION)(rand() % 4));
	fruit.setAppearance('5' + rand() % 5);
	fruit.setTimeToDisappear(OPTIONS::MIN_FRUIT_APPEARENCE + rand() % OPTIONS::FRUIT_OFFSET);
}

void PacmanGame::removeFruit()
{
	displayByApperance(fruit.getPosition(), board.get(fruit.getPosition()));
	fruit.setDisplayed(false);
	fruit.setNextTimeAppear(OPTIONS::MIN_FRUIT_DISAPPEARENCE + rand() % OPTIONS::FRUIT_OFFSET);
}

bool PacmanGame::updateLineToGame(string line, int currHeight, int &pacmanCounter, int &legendCounter)
{
	bool succeed = true;
	int lineLength = static_cast<int>(line.length());
	for (int i = 0; i < lineLength && i < board.getLogicalWidth() - 1; i++)
	{
		switch ((int)line[i])
		{
		case (int)FILE_FIGURES::BREAD_CRUMBS:
			board.set(i, currHeight, (char)FIGURES::BREAD_CRUMBS);
			breadCrumbs++;
			break;
		case (int)FILE_FIGURES::GHOST:
			if (ghosts.size() == 4)
			{
				cout << "ERROR: Board couldn't loaded: There are too many ghost on this board";
				return false;
			}
			board.setGhostsInitial(i, currHeight, static_cast<int>(ghosts.size()));
			ghosts.push_back(Ghost(Position(i, currHeight)));
			board.set(i, currHeight, ' ');
			break;
		case (int)FILE_FIGURES::LEGEND:
			if (legendCounter == 1)
			{
				cout << "ERROR: Board couldn't loaded:  There are too many legends on this board";
				return false;
			}
			if (i + 20 > board.getLogicalWidth() || i + 20 > board.WIDTH)
			{
				cout << "ERROR: Board couldn't loaded: There is not enough space to the legend area";
				return false;
			}
			board.setLegendStartingPoint(i, currHeight);
			board.set(i, currHeight, ' ');
			board.setOffset(i, currHeight);
			legendCounter++;
			break;
		case (int)FILE_FIGURES::NOTHING:
			board.set(i, currHeight, ' ');
			break;
		case (int)FILE_FIGURES::PACMAN:
			if (pacmanCounter == 1)
			{
				cout << "ERROR: Board couldn't loaded:  There are too many pacmans on this board";
				return false;
			}
			board.setPacmanInitials(i, currHeight);
			pacman = Pacman(Position(i, currHeight));
			board.set(i, currHeight, ' ');
			pacmanCounter++;
			break;
		case (int)FILE_FIGURES::WALL:
			board.set(i, currHeight, (char)FIGURES::WALL);
			break;
		default:
			cout << "ERROR: Board couldn't loaded:   There are no support for this type of char";
			return false;
			break;
		}
	}
	board.set(board.getLogicalWidth() - 1, currHeight, '\n');
	return succeed;
}

void PacmanGame::readBoardsNames()
{
	//the function get from the directory lexicograficly sorted strings
	std::string path = ".";
	for (const auto& entry : fs::directory_iterator(path))
	{
		if (entry.path().string().ends_with(".screen"))
			fileNames.push_back(entry.path().string());
	}
	std::sort(fileNames.begin(), fileNames.end(), custom);
}

bool PacmanGame::isValidOption(char key)
{
	return (key == Menu::OPTIONS::START_GAME_WITH_COLORS) || (key == Menu::OPTIONS::START_GAME_WITHOUT_COLORS) ||
		(key == Menu::OPTIONS::PRESENT_KEYS) || (key == Menu::OPTIONS::EXIT);
}

bool PacmanGame::isValidLevel(char userChoice)
{
	return (userChoice == LEVEL::BEST) || (userChoice == LEVEL::GOOD) || (userChoice == LEVEL::NOVICE);
}

bool PacmanGame::isValidLoadMethod(char userChoice)
{
	return (userChoice == Menu::OPTIONS::LOAD_BY_NAME) || (userChoice == Menu::OPTIONS::LOAD_ALL_FILES);
}

void PacmanGame::run()
{
	char key = 0;
	int pacmanSteps = 0; //also represents the term "point in time"
	string steps_file_name, result_file_name, postfix = ".screen";
	fstream steps_file, result_file;
	bool steps_changes[8] = { 0 };
	bool result_changes[2] = { 0 };
	if (playMode == PLAY_MODE::SAVE)
	{
		int postfixlen = postfix.length();
		steps_file_name = fileNames[gameNumber].substr(0, fileNames[gameNumber].length() - postfixlen) + ".steps";
		result_file_name = fileNames[gameNumber].substr(0, fileNames[gameNumber].length() - postfixlen) + ".result";
		steps_file.open(steps_file_name, ios::trunc | ios::out);
		if (!steps_file)
		{
			throw "ERROR: couldn't open steps file";
		}
		result_file.open(result_file_name, ios::trunc | ios::out);
		if (!result_file)
		{
			throw "ERROR: couldn't open result file";
		}
	}
	while (breadCrumbs > 0 && lives > 0)
	{
		if (_kbhit())
		{
			key = _getch();
			if (key == ESC)
			{
				while (!_kbhit() || _getch() != ESC) {}
			}
			else
			{
				if ((DIRECTION)pacman.getDirectionByChar(key) != pacman.getDirection())
					steps_changes[STEPS_CHANGES::PACMAN] = true;
				pacman.setDirection(key);
			}
		}
		movePacman(result_changes);
		hideCursor();
		if (PLAY_MODE::SAVE == playMode)
		{
			//update to steps file
			updateStepsFile(steps_file, pacmanSteps, steps_changes);
			//update to result file
			updateResultFile(result_file, pacmanSteps, result_changes);
			for (int i = 0; i < sizeof(steps_changes) / sizeof(steps_changes[0]); i++)
				steps_changes[i] = false;
			for (int i = 0; i < sizeof(result_changes) / sizeof(result_changes[0]); i++)
				result_changes[i] = false;
		}
		pacmanSteps++;
		if (pacmanSteps % OPTIONS::GHOST_SPEED == 0)
		{
			moveGhosts(steps_changes, result_changes);
			hideCursor();
		}
		if (!fruit.getDisplayed())
		{
			fruit.setNextTimeAppear(fruit.getNextTimeAppear() - 1);
			if (fruit.getNextTimeAppear() == 0)
			{
				initFruit();
				steps_changes[STEPS_CHANGES::FRUIT_APPEAR] = true;
			}
		}
		else // fruit displayed
		{
			fruit.setTimeToDisappear(fruit.getTimeToDisappear() - 1);
			if (fruit.getTimeToDisappear() == 0)
			{
				removeFruit();
				steps_changes[STEPS_CHANGES::FRUIT_DISAPPEAR] = true;
			}
			else if (pacmanSteps % OPTIONS::FRUIT_SPEED == 0)
			{
				moveFruit(steps_changes);
				hideCursor();
			}
		}
		Sleep(OPTIONS::GAME_SPEED);
	}
	clear_screen();
	winCheck(result_changes);
	if (playMode == PLAY_MODE::SAVE)
	{
		//update to steps file
		updateStepsFile(steps_file, pacmanSteps, steps_changes);
		//update result file
		updateResultFile(result_file, pacmanSteps, result_changes);
		steps_file.close();
		result_file.close();
	}
}

bool PacmanGame::runLoad()
{
	char key = 0;
	bool spam[10];
	int pacmanSteps = 0, pointInTimeSteps, pointInTimeResult;
	string steps_file_name, result_file_name, postfix = ".screen";
	fstream steps_file, result_file;
	bool result_changes_game[2] = { 0 }, result_changes_file[2] = { 0 };
	int postfixlen = postfix.length();
	steps_file_name = fileNames[gameNumber].substr(0, fileNames[gameNumber].length() - postfixlen) + ".steps";
	result_file_name = fileNames[gameNumber].substr(0, fileNames[gameNumber].length() - postfixlen) + ".result";
	steps_file.open(steps_file_name, ios::in);
	if (!steps_file)
	{
		throw "ERROR: couldn't open steps file";
	}
	result_file.open(result_file_name, ios::in);
	if (!result_file)
	{
		throw "ERROR: couldn't open result file";
	}
	steps_file >> pointInTimeSteps;
	result_file >> pointInTimeResult;
	while (breadCrumbs > 0 && lives > 0)
	{
		movePacman(result_changes_game);
		hideCursor();
		if (pointInTimeResult == pacmanSteps)
		{
			updateLineToResult(result_file, result_changes_file);
			if (playMode == PLAY_MODE::LOAD_SILENT && !resultComparison(result_changes_game, result_changes_file))
			{
				steps_file.close();
				result_file.close();
				return false;
			}
			result_file >> pointInTimeResult;
			for (int i = 0; i < RESULT_CHANGES::RESULT_SIZE; i++)
			{
				result_changes_game[i] = false;
				result_changes_file[i] = false;
			}
		}
		pacmanSteps++;
		if (pointInTimeSteps == pacmanSteps)
		{
			setLineToGame(steps_file);
			steps_file >> pointInTimeSteps;
		}
		if (pacmanSteps % OPTIONS::GHOST_SPEED == 0)
		{
			moveGhosts(spam, result_changes_game);
			hideCursor();
		}
		if (fruit.getDisplayed() && pacmanSteps % OPTIONS::FRUIT_SPEED == 0)
		{
			moveFruit(spam);
			hideCursor();
		}
		if(playMode==PLAY_MODE::LOAD)
			Sleep(OPTIONS::GAME_SPEED);
	}
	clear_screen();
	winCheck(result_changes_game);
	if (pointInTimeResult == pacmanSteps)
	{
		updateLineToResult(result_file, result_changes_file);
	}
	if (playMode == PLAY_MODE::LOAD_SILENT && !resultComparison(result_changes_game, result_changes_file))
	{
		steps_file.close();
		result_file.close();
		return false;
	}
	steps_file.close();
	result_file.close();
	return true;
}

bool PacmanGame::resultComparison(bool *result_changes_game, bool *result_changes_file)
{
	return result_changes_game[0] == result_changes_file[0] && result_changes_game[1] == result_changes_file[1];
}

void PacmanGame::setLineToGame(fstream& steps_file)
{
	string line;
	long startLinePos = steps_file.tellg(), endInputPos, currPos;
	getline(steps_file, line);
	endInputPos = steps_file.tellg();
	//go back 1 for the " " at the end and 2 for the "/n" when go to the next line
	endInputPos -= 3;
	steps_file.seekg(startLinePos);
	currPos = steps_file.tellg();
	while (currPos != endInputPos && currPos != EOF) {
		setCreatureToGame(steps_file);
		currPos = steps_file.tellg();
	}

}

void PacmanGame::updateLineToResult(fstream& result_file, bool* result_changes_file)
{
	string line;
	int result;
	long startLinePos = result_file.tellg();
	long endInputPos;
	getline(result_file, line);
	endInputPos = result_file.tellg();
	//go back 1 for the " " at the end and 2 for the "/n" when go to the next line
	endInputPos -= 3;
	result_file.seekg(startLinePos); 
	while (result_file.tellg() != endInputPos && endInputPos != EOF)
	{
		result_file >> result;
		switch (result)
		{
		case RESULT_CHANGES::PACMAN_DIED:
			result_changes_file[RESULT_CHANGES::PACMAN_DIED] = true;
			break;
		case RESULT_CHANGES::FINISHED_SCREEN:
			result_changes_file[RESULT_CHANGES::FINISHED_SCREEN] = true;
			break;
		default:
			break;
		}
	}
}

void PacmanGame::setCreatureToGame(fstream& steps_file)
{
	int creature, directionToMove, fruitXPos, fruitYPos;
	bool spam[10], resultToCompare[2];
	Position fruitPos;
	char fruitAppearence;
	steps_file >> creature;
	switch (creature)
	{
	case STEPS_CHANGES::PACMAN:
		steps_file >> directionToMove;
		pacman.Creature::setDirection((DIRECTION)directionToMove);
		break;
	case STEPS_CHANGES::GHOST0:
		steps_file >> directionToMove;
		ghosts[0].setDirection((DIRECTION)directionToMove);
		break;
	case STEPS_CHANGES::GHOST1:
		steps_file >> directionToMove;
		ghosts[1].setDirection((DIRECTION)directionToMove);
		break;
	case STEPS_CHANGES::GHOST2:
		steps_file >> directionToMove;
		ghosts[2].setDirection((DIRECTION)directionToMove);
		break;
	case STEPS_CHANGES::GHOST3:
		steps_file >> directionToMove;
		ghosts[3].setDirection((DIRECTION)directionToMove);
		break;
	case STEPS_CHANGES::FRUIT:
		steps_file >> directionToMove;
		fruit.setDirection((DIRECTION)directionToMove);
		break;
	case STEPS_CHANGES::FRUIT_APPEAR:
		steps_file >> fruitXPos >> fruitYPos >> fruitAppearence >> directionToMove;
		fruitPos = Position(fruitXPos, fruitYPos);
		fruit.setPosition(fruitPos);
		fruit.setNextTimeAppear(0);
		fruit.setDisplayed(true);
		fruit.setDirection((DIRECTION)directionToMove);
		fruit.setAppearance(fruitAppearence);
		fruit.setTimeToDisappear(OPTIONS::MIN_FRUIT_APPEARENCE + rand() % OPTIONS::FRUIT_OFFSET);
		break;
	case STEPS_CHANGES::FRUIT_DISAPPEAR:
		removeFruit();
		break;
	default:
		break;
	}
}

void PacmanGame::winCheck(bool *result_changes)
{
	if (playMode != PLAY_MODE::LOAD_SILENT)
	{
		if (breadCrumbs == 0)
			cout << "Congratulations, you won the game!!!" << endl;
		else
			cout << "you lose :(" << endl;
	}
	result_changes[RESULT_CHANGES::FINISHED_SCREEN] = true;
}

void PacmanGame::moveFruit(bool* steps_changes)
{
	Position pacmanPosition = pacman.getPosition();
	Position fruitCurrPosition = fruit.getPosition();
	Position fruitNextMove = board.getNextPosition(fruitCurrPosition, fruit.getDirection(), false);
	bool isWallInD[4];
	while (board.isWall(fruitNextMove) && (playMode==PLAY_MODE::NORMAL || playMode == PLAY_MODE::SAVE))
	{
		//need to change current direction
		DIRECTION newDirection;
		isWallInD[(int)fruit.getDirection()] = true;
		newDirection = (DIRECTION)(rand() % 4);
		while (isWallInD[(int)newDirection] == true)
			newDirection = (DIRECTION)(rand() % 4);
		//update ghost next move if needed
		fruitNextMove = board.getNextPosition(fruitCurrPosition, newDirection, false);
		if (newDirection != fruit.getDirection())
			steps_changes[STEPS_CHANGES::FRUIT] = true;
		fruit.setDirection(newDirection);
	}
	fruit.setPosition(fruitNextMove);
	displayByApperance(fruitCurrPosition, board.get(fruitCurrPosition));
	displayByApperance(fruitNextMove, fruit.getAppearance());
	if (checkFruitCollision(pacman.getPosition()))
	{
		score += fruit.getValue();
		removeFruit();
		printScore();
	}
	if (fruit.getDisplayed() && checkGhostCollisions(fruitNextMove))
		removeFruit();
}

bool PacmanGame::checkFruitCollision(Position p)
{
	return fruit.getDisplayed() && fruit.getPosition().equals(p);
}

void PacmanGame::movePacman(bool* result_changes)
{
	//gets pacman next position
	Position currPosition = pacman.getPosition();
	Position newPosition = board.getNextPosition(currPosition, pacman.getDirection(), true);
	//stand on ghost 
	if (checkGhostCollisions(newPosition))
	{
		actOnGhostCollision(result_changes);
		return;
	}
	//stand on fruit
	if (checkFruitCollision(newPosition))
	{
		score += fruit.getValue();
		removeFruit();
		printScore();
	}

	//stand on bread crumb
	if (board.isContainsBreadcrumbs(newPosition))
	{
		score++;
		breadCrumbs--;
		printScore();
		board.set(newPosition, ' ');
	}
	//stand in wall
	else if (board.isWall(newPosition))
	{
		newPosition = pacman.getPosition();
		pacman.Creature::setDirection(DIRECTION::STAY);
	}
	displayByApperance(currPosition, board.get(currPosition));
	displayByApperance(newPosition, pacman.getAppearance());
	pacman.setPosition(newPosition);
}

bool PacmanGame::checkGhostCollisions(Position& newPosition)
{
	for (int i = 0; i < ghosts.size(); i++)
	{
		if (ghosts[i].getPosition().equals(newPosition)) {
			return true;
		}
	}
	return false;
}

void PacmanGame::actOnGhostCollision(bool* result_changes)
{
	result_changes[RESULT_CHANGES::PACMAN_DIED] = true;
	lives--;
	printLives();
	setInitialPositions(true);
}

void PacmanGame::changeColor(char apperance)
{
	switch (apperance)
	{
	case((int)FIGURES::BREAD_CRUMBS):
		setTextColor((Color)FIGURES_COLORS::cBREAD_CRUMBS);
		break;
	case((int)FIGURES::GHOST):
		setTextColor((Color)FIGURES_COLORS::cGHOST);
		break;
	case((int)FIGURES::PACMAN):
		setTextColor((Color)FIGURES_COLORS::cPACMAN);
		break;
	case((int)FIGURES::WALL):
		setTextColor((Color)FIGURES_COLORS::cWALL);
		break;
	case((int)FIGURES::FRUIT_5):
		setTextColor((Color)FIGURES_COLORS::cFRUIT);
		break;
	case((int)FIGURES::FRUIT_6):
		setTextColor((Color)FIGURES_COLORS::cFRUIT);
		break;
	case((int)FIGURES::FRUIT_7):
		setTextColor((Color)FIGURES_COLORS::cFRUIT);
		break;
	case((int)FIGURES::FRUIT_8):
		setTextColor((Color)FIGURES_COLORS::cFRUIT);
		break;
	case((int)FIGURES::FRUIT_9):
		setTextColor((Color)FIGURES_COLORS::cFRUIT);
		break;
	default:
		setTextColor(Color::WHITE);
		break;
	}
}

void PacmanGame::displayByApperance(Position p, char apperance)
{
	if (playMode == PLAY_MODE::LOAD_SILENT)
		return;
	if (enableColor)
		changeColor(apperance);
	gotoxy(p.getX(), p.getY());
	cout << apperance;
}

void PacmanGame::moveGhosts(bool* steps_changes, bool* result_changes)
{
	ghostsTurnNumber++;
	Position pacmanPosition = pacman.getPosition();
	Position fruitPosition = fruit.getPosition();
	for (int i = 0; i < ghosts.size(); i++)
	{
		Position ghostCurrPosition = ghosts[i].getPosition();
		if (playMode == PLAY_MODE::NORMAL || playMode == PLAY_MODE::SAVE)
		{
			DIRECTION newDirection = strategy->getNextDirection(board, ghosts[i], pacmanPosition);
			if (newDirection != ghosts[i].getDirection())
				steps_changes[STEPS_CHANGES::GHOST0 + i] = true;
			ghosts[i].setDirection(newDirection);
		}
		Position ghostNextMove = board.getNextPosition(ghostCurrPosition, ghosts[i].getDirection(), false);
		//check if ghost next move is wall in case of dumb
		if (board.isWall(ghostNextMove))
		{
			ghostNextMove = ghostCurrPosition;
		}
		ghosts[i].setPosition(ghostNextMove);
		displayByApperance(ghostCurrPosition, board.get(ghostCurrPosition));
		displayByApperance(ghostNextMove, (char)FIGURES::GHOST);
	}
	if (checkGhostCollisions(pacmanPosition))
		actOnGhostCollision(result_changes);
	if (fruit.getDisplayed() && checkGhostCollisions(fruitPosition))
		removeFruit();
}

void PacmanGame::printLives()
{
	Position p = board.getLivesPosition();
	gotoxy(p.getX(), p.getY());
	if (enableColor)
		setTextColor(Color::RED);
	cout << lives;
}

void PacmanGame::printScore()
{
	Position p = board.getScorePosition();
	gotoxy(p.getX(), p.getY());
	if (enableColor)
		setTextColor(Color::LIGHTCYAN);
	cout << score;
}

