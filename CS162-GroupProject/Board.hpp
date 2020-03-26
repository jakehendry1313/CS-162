/*********************************************************************
** CS 162: Group Project
**
** Program: predatorPrey
** File:    Board.hpp
** Author:  Michael Copland
** Date:    2019-04-24
** -------------------------------------------------------------------
** This is the Board class specification (header) file. The Board
** values are initialized based on whether the game is started with the
** extra credit option for custom amounts.
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"

#include <iostream>             // cout
#include <stdlib.h>             // rand()

using std::cout;

class Board {
    enum cells {SPACE, ANT, DOODLEBUG};
	enum direction {UP, DOWN, LEFT, RIGHT};

    private:
        int ants, doodlebugs, columns, rows, steps;
		int oldRow, oldCol;		// <--- Keeps track of previous position
        Critter ***gameBoard;
    public:
        Board(bool);            /* creates a board based on whether
                                   extra credit option is chosen */
        ~Board();
        void fillBoard();       /* randomly place ants and doodlebugs
                                   on board */
        void moveCritters();    /* loops through board and moves each
                                   Critter, transforming board as needed */
		void printBoard();      // prints the board

		void findOccupied(int i, int j);
		void resetOccupy(int i, int j);

		// setters and getters
		void setAnts(int userAnts);
		void setDoodlebugs(int userDoodle);
		void setColumns(int userColumns);
		void setRows(int userRows);
		void setSteps(int userSteps);

		int getAnts();
		int getDoodlebugs();
		int getColumns();
		int getRows();
		int getSteps();

};

#endif
