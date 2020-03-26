/*********************************************************************
** CS 162: Group Project
**
** Program: predatorPrey
** File:    Board.cpp
** Author:  Michael Copland
** Date:    2019-04-24
** -------------------------------------------------------------------
** This is the Board class function implementation file. The Board
** values are initialized based on whether the game is started with the
** extra credit option for custom amounts.
*********************************************************************/

#include "Board.hpp"

/*
** Constructor for Board class.
**
** @param bool  Determines if game starts with extra credit option.
*/
Board::Board(bool customGame) {

	ants = 1;
	doodlebugs = 1;
	rows = 10;
	columns = 10;

    if (!customGame) { // Default Attributes
        ants = 100;
        doodlebugs = 5;
        rows = 20;
        columns = 20;
    }
    else {
        // acquired through Menu, main, ... <-------------------------
 		ants = getAnts();
        doodlebugs = getDoodlebugs();
        rows = getRows();
        columns = getColumns();
    }

    steps = getSteps();
}

/*
** Destructor for Board class. Frees dynamically allocated memory.
*/
Board::~Board() {
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j) {
            delete gameBoard[i][j];
        }
        delete [] gameBoard[i]; 
    }

    delete [] gameBoard;
}

/*
** Randomly fills the Board with Ants and Doodlebugs
*/
void Board::fillBoard() {

	// initialize board
	gameBoard = new Critter**[rows];
	for (int i = 0; i < rows; ++i) {
		gameBoard[i] = new Critter*[columns];

		for (int j = 0; j < columns; ++j) {
			gameBoard[i][j] = nullptr;
		}
	}

	int randomRow = rand() % rows;
    int randomCol = rand() % columns;
	
	
    for(int i = 0; i < ants; ++i) {
        while (gameBoard[randomRow][randomCol] != nullptr) {
            randomRow = rand() % rows;
            randomCol = rand() % columns;
        }
        // Place new Ant
       gameBoard[randomRow][randomCol] = new Ant(randomRow, randomCol); 
    }

    for(int i = 0; i < doodlebugs; ++i) {
        while (gameBoard[randomRow][randomCol] != nullptr) {
            randomRow = rand() % rows;
            randomCol = rand() % columns;
        }
      // Place new Doodlebug
      gameBoard[randomRow][randomCol] = new Doodlebug(randomRow, randomCol); 
    }
	
}

/*
** Parameters: two integers representing board coords
** This function checks if neighboring cells are occupied and then
** marks given bool occupy variables as true. In addition, it also
** notes if there is a surrounding ant.
*/

void Board::findOccupied(int i, int j)
	{
	if ((i + 1) <= (rows - 1))
	{ 
		if (gameBoard[i + 1][j] != nullptr)
		{
			gameBoard[i][j]->setOccupyDown(true);

			if (gameBoard[i+1][j]->getType() == ANT) 
				{
					gameBoard[i][j]->setAntDown(true);
				}
		}
	}	

	if ((i - 1) >= 0)
	{ 
		if (gameBoard[i - 1][j] != nullptr)
		{
			gameBoard[i][j]->setOccupyUp(true);
			if (gameBoard[i-1][j]->getType() == ANT) 
				{
					gameBoard[i][j]->setAntUp(true);
				}
		}
	}

	if ((j + 1) <= (columns - 1))
	{
		if (gameBoard[i][j + 1] != nullptr)
		{
			gameBoard[i][j]->setOccupyRight(true);
			if (gameBoard[i][j+1]->getType() == ANT) 
				{
					gameBoard[i][j]->setAntRight(true);
				}
		}
	}
	if ((j - 1) >= 0)
	{ 
		if (gameBoard[i][j - 1] != nullptr)
		{
			gameBoard[i][j]->setOccupyLeft(true);

			if (gameBoard[i][j-1]->getType() == ANT) 
				{
					gameBoard[i][j]->setAntLeft(true);
				}
		}
	}
}

/*
** Parameters, two integers representing board coords
** resetOccupy resets occupy bool variables
*/
void Board::resetOccupy(int i, int j)
{
	gameBoard[i][j]->setOccupyDown(false);
	gameBoard[i][j]->setOccupyUp(false);
	gameBoard[i][j]->setOccupyLeft(false);
	gameBoard[i][j]->setOccupyRight(false);
	gameBoard[i][j]->setAntUp(false);
	gameBoard[i][j]->setAntDown(false);
	gameBoard[i][j]->setAntRight(false);
	gameBoard[i][j]->setAntLeft(false);
}

/*
** Moves all Critters on board, deletes any starving Doodlebugs, then
** calls the breed function on remaining Critters.
*/
void Board::moveCritters() {

	/* 
	Resets movedAlready variable and sends max row and column info to critter
	and  neighboring cell check
	*/
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (gameBoard[i][j] != nullptr)
			{
				gameBoard[i][j]->setMovedAlready(false);
				gameBoard[i][j]->setMaxRow(rows);
				gameBoard[i][j]->setMaxCol(columns);
				resetOccupy(i, j);
			}
		}
	}

    // move all Doodlebugs
    int tempcount=0;

	for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if ((gameBoard[i][j] != nullptr) && (gameBoard[i][j]->getType() == DOODLEBUG) && !(gameBoard[i][j]->getMovedAlready())) {
				
				tempcount++;
				// 2. Tracks previous position of ant
				oldRow = gameBoard[i][j]->getRow();
				oldCol = gameBoard[i][j]->getCol();

				findOccupied(i,j);
                gameBoard[i][j]->move();
                
			   	gameBoard[i][j]->incrementStepsToBreed();
		
				// 5. If the new coordinates are different, moves position
				if (gameBoard[oldRow][oldCol] != gameBoard[gameBoard[i][j]->getRow()][gameBoard[i][j]->getCol()])
				{
					// check to see if there is currently an ant in space so it can be deleted.

					if (gameBoard[gameBoard[i][j]->getRow()][gameBoard[i][j]->getCol()] != nullptr)
					{

						if (gameBoard[gameBoard[i][j]->getRow()][gameBoard[i][j]->getCol()]->getType() == ANT)
							{
							delete gameBoard[gameBoard[i][j]->getRow()][gameBoard[i][j]->getCol()];	
							}
					}

					// Set pointer to new space
					gameBoard[gameBoard[i][j]->getRow()][gameBoard[i][j]->getCol()] = gameBoard[i][j];
					
					// Make old space empty
					gameBoard[i][j] = nullptr;
				}
				else
				{
					gameBoard[i][j]->setRow(oldRow);
					gameBoard[i][j]->setCol(oldCol);
				}
       	 		}
		}
	}
		

	for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
			if (gameBoard[i][j] != nullptr)
			{
				// Breed Doodlebugs
				if (gameBoard[i][j]->getType() == DOODLEBUG && gameBoard[i][j]->getBreedStatus())
				{
					resetOccupy(i, j);
					findOccupied(i, j);
					Critter* createdDoodlebug = nullptr;

					createdDoodlebug = gameBoard[i][j]->breed();

					if (createdDoodlebug != nullptr)
					{
						gameBoard[createdDoodlebug->getRow()][createdDoodlebug->getCol()] = createdDoodlebug;
						gameBoard[i][j]->resetBreedClock();
					}
				}
				
				// Starve Doodlebugs
				if ((gameBoard[i][j]->getType() == DOODLEBUG) && gameBoard[i][j]->starve())
				{
					delete gameBoard[i][j];
					gameBoard[i][j] = nullptr;
				}
				
			}
		
        }
    }

    // move all Ants
    for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < columns; j++)
		{
			if (gameBoard[i][j] != nullptr)
			{
				// 1. Checks if they are an ant and if the ant has made a move attempt.
				if (gameBoard[i][j]->getType() == ANT && !(gameBoard[i][j]->getMovedAlready()))
				{
					// 2. Tracks previous position of ant
					oldRow = gameBoard[i][j]->getRow();
					oldCol = gameBoard[i][j]->getCol();

					// 3. Checks neighboring cells. Marks the cell as occupied if there is a bug inside
					findOccupied(i, j);
					// 4. Performs movement process
					gameBoard[i][j]->move();
					gameBoard[i][j]->incrementStepsToBreed();

					// 5. If the new coordinates are different, moves position
					if (gameBoard[oldRow][oldCol] != gameBoard[gameBoard[i][j]->getRow()][gameBoard[i][j]->getCol()])
					{
						// Set pointer to new space
						gameBoard[gameBoard[i][j]->getRow()][gameBoard[i][j]->getCol()] = gameBoard[i][j];
						// Make old space empty
						gameBoard[i][j] = nullptr;
					}
					else
					{
						gameBoard[i][j]->setRow(oldRow);
						gameBoard[i][j]->setCol(oldCol);
					}
				}
			}
		}
	}

    for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < columns; j++)
		{

			if (gameBoard[i][j] != nullptr) // Breed Ants
			{
				if ((gameBoard[i][j]->getType() == ANT) && (gameBoard[i][j]->getBreedStatus()))
				{
					resetOccupy(i, j);
					findOccupied(i, j);
					Critter* createdAnt = nullptr;

					createdAnt = gameBoard[i][j]->breed();

					if (createdAnt != nullptr)
					{
						gameBoard[createdAnt->getRow()][createdAnt->getCol()] = createdAnt;
						gameBoard[i][j]->resetBreedClock();
					}
				}
			}
        }
	}
		    
}
	


/*
** Loops through the array and prints their values.
*/
void Board::printBoard() {
    // loop through rows and columns, print their values
    for (int i = 0; i < rows; ++i) {
        // print left edge
        cout << "|";
        for (int j = 0; j < columns; ++j) {
            // print cell value 
            if(gameBoard[i][j] != nullptr) {
                if(gameBoard[i][j]->getType() == ANT) {
                    cout << " O |";
                }
                else {
                    cout << " X |";
                }
            }
            else {
                cout << "   |";
            }
        }
        cout << std::endl;
    }
}

// Setters and getters

void Board::setAnts(int userAnts)
{
	ants = userAnts;
}

void Board::setDoodlebugs(int userDoodle)
{
	doodlebugs = userDoodle;
}

void Board::setColumns(int userColumns)
{
	columns = userColumns;
}

void Board::setRows(int userRows)
{
	rows = userRows;
}

void Board::setSteps(int userSteps)
{
	steps = userSteps;
}

int Board::getAnts()
{
	return ants;
}

int Board::getDoodlebugs()
{
	return doodlebugs;
}

int Board::getColumns()
{
	return columns;
}

int Board::getRows()
{
	return rows;
}

int Board::getSteps()
{
	return steps;
}



