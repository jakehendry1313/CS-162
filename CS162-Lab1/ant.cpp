/*****************************************************************************
** Program name: Project 1 - ant.cpp
** Author:       Jacob Hendry
** Date:         4/14/2019
** Description:  This file will implement the ant header file that includes
**               the ant class that will layout all of the functions and 
**               variables needed to print the ant on to the board and 
**               determine each step of the ant's position.
*****************************************************************************/
#include <iostream>
#include "ant.hpp"

using std::cout;
using std::endl;


//This implements the Ant's constructor from the header file show the board and ant position.
Ant::Ant(char ** boardInput, int rowStartInput, int colStartInput, int rowInput, int colInput)
{
     board = boardInput;
     numOfRows = rowInput;
     numOfCols = colInput;

     for (int row = 0; row < numOfRows; row++)
     {
          for (int col = 0; col < numOfCols; col++)
          {
               board[row][col] = ' ';
          }
     }
     rowPosition = rowStartInput;
     colPosition = colStartInput;
}

//Function to get the row's starting position for the ant
int Ant::getRowPosition()
{
     return rowPosition;
}

//Function to get the column's starting position for the ant
int Ant::getColPosition()
{
     return colPosition;
}

//Function to determine the number of rows the user would like to use
int Ant::getRowStart()
{
     return numOfRows;
}

//Function to determine the number of columns the user would like to use
int Ant::getColStart()
{
     return numOfCols;
}

//Function that will print out the board for the user to see
void Ant::printBoard()
{
     int numOfRows = getRowStart();
     int numOfCols = getColStart();

     cout << endl;

     for (int row = 0; row < numOfRows; row++)
     {
          for (int col = 0; col < numOfCols; col++)
          {
               cout << board[row][col];
          }
          cout << endl;
     }
}
/************************************************************************
This function will implement the makeMove function that will determine
the position of the ant and then move the ant a specific amount of steps
and then move the ant either up, down, left, or right based on location
************************************************************************/
void Ant::makeMove(char ** board, int rowPosition, int colPosition, int steps)
{
     direction orientation = UP;

     rowPosition -= 1;
     colPosition -= 1;

     board[rowPosition][colPosition] = '#';

     for (int count = 0; count < steps; count++)
     {
          switch (orientation)
          {
          case UP:
               if ((rowPosition - 1) < 0)
               {
                    orientation = DOWN;
                    count--;
                    break;
               }

               if (board[rowPosition - 1][colPosition] == ' ')
               {
                    rowPosition -= 1;
                    board[rowPosition][colPosition] = '*';
                    orientation = nextPosition(UP, ' ');
                    printBoard();
                    board[rowPosition][colPosition] = '#';
                    break;
               }

               if (board[rowPosition - 1][colPosition] == '#')
               {
                    rowPosition -= 1;
                    board[rowPosition][colPosition] = '*';
                    orientation = nextPosition(UP, '#');
                    printBoard();
                    board[rowPosition][colPosition] = ' ';
                    break;
               }

          case RIGHT:
               if ((colPosition + 1) > (numOfCols - 1))
               {
                    orientation = LEFT;
                    count--;
                    break;
               }

               if (board[rowPosition][colPosition + 1] == ' ')
               {
                    colPosition += 1;
                    board[rowPosition][colPosition] = '*';
                    orientation = nextPosition(LEFT, ' ');
                    printBoard();
                    board[rowPosition][colPosition] = '#';
                    break;
               }

               if (board[rowPosition][colPosition + 1] == '#')
               {
                    colPosition += 1;
                    board[rowPosition][colPosition] = '*';
                    orientation = nextPosition(LEFT, '#');
                    printBoard();
                    board[rowPosition][colPosition] = ' ';
                    break;
               }

          case DOWN:
               if ((rowPosition + 1) > (numOfRows - 1))
               {
                    orientation = UP;
                    count--;
                    break;
               }

               if (board[rowPosition + 1][colPosition] == ' ')
               {
                    rowPosition += 1;
                    board[rowPosition][colPosition] = '*';
                    orientation = nextPosition(DOWN, ' ');
                    printBoard();
                    board[rowPosition][colPosition] = '#';
                    break;
               }

               if (board[rowPosition + 1][colPosition] == '#')
               {
                    rowPosition += 1;
                    board[rowPosition][colPosition] = '*';
                    orientation = nextPosition(DOWN, '#');
                    printBoard();
                    board[rowPosition][colPosition] = ' ';
                    break;
               }

          case LEFT:
               if ((colPosition - 1) < 0)
               {
                    orientation = RIGHT;
                    count--;
                    break;
               }

               if (board[rowPosition][colPosition - 1] == ' ')
               {
                    colPosition -= 1;
                    board[rowPosition][colPosition] = '*';
                    orientation = nextPosition(LEFT, ' ');
                    printBoard();
                    board[rowPosition][colPosition] = '#';
                    break;
               }

               if (board[rowPosition][colPosition - 1] == '#')
               {
                    colPosition -= 1;
                    board[rowPosition][colPosition] = '*';
                    orientation = nextPosition(LEFT, '#');
                    printBoard();
                    board[rowPosition][colPosition] = ' ';
                    break;
               }
          }
     }
}

/*****************************************************************
This function will implement the direction statement that will
determine which way the ant will turn based on the location of
the ant and whether it is a black or white space.
*/
direction Ant::nextPosition(direction orientation, char condition)
{
     direction nextPosition = UP;

     if (condition == '#')
     {
          switch (orientation)
          {
          case UP:
               nextPosition = LEFT;
               return nextPosition;
               break;

          case DOWN:
               nextPosition = RIGHT;
               return nextPosition;
               break;

          case RIGHT:
               nextPosition = UP;
               return nextPosition;
               break;

          case LEFT:
               nextPosition = DOWN;
               return nextPosition;
               break;
          }
     }

     else if (condition == ' ')
     {
          switch (orientation)
          {
          case UP:
               nextPosition = RIGHT;
               return nextPosition;
               break;

          case DOWN:
               nextPosition = LEFT;
               return nextPosition;
               break;

          case RIGHT:
               nextPosition = DOWN;
               return nextPosition;
               break;

          case LEFT:
               nextPosition = UP;
               return nextPosition;
               break;
          }
     }

     return nextPosition;
}