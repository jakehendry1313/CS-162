/*****************************************************************************
** Program name: Project 1 - ant.hpp
** Author:       Jacob Hendry
** Date:         4/14/2019
** Description:  This is the header file that includes the class called Ant. 
**               The class Ant will determine the direction of ant as well
**               as the positions based on the row and column. The ant will
**               will be represented by a * character and the spaces the ant
**               has moved will be represented by a # (blank space). 
****************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

enum direction { UP, DOWN, RIGHT, LEFT };

class Ant
{
/**********************************************************
     A pointer to a pointer for the char of the ant,
     use of an enum to determine the direction of the ant,
     also start and location of the ant's position.*
**********************************************************/
private:
     char ** board;
     direction orientation;
     int numOfRows, numOfCols;
     int rowPosition, colPosition;
/*********************************************************
This includes the constructor for the class Ant, get 
methods for the start and location of the ant, use of a
void functions to print the board, move the ant, and
determine the next positionn for the ant on the board.
*********************************************************/
public:
     Ant(char **, int, int, int, int);
     int getRowPosition();
     int getColPosition();
     int getRowStart();
     int getColStart();
     void printBoard();
     void makeMove(char **, int, int, int);
     direction nextPosition(direction, char);
};

#endif