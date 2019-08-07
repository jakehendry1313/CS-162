/*****************************************************************************
** Program name: Project 1 - antMain.cpp
** Author:       Jacob Hendry
** Date:         4/14/2019
** Description:  This main file will implement every file included such as
**               the menu function and header as well as the ant with the
**               board.
*****************************************************************************/
#include <iostream>
#include "ant.hpp"
#include "menuFunction.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
     //Inputs the user's choice from the menu function
     int userInput = menu();

     //If 1 is chosen, Langton's Ant program will run
     while (userInput == 1)
     {
          int userRows, userCols, userSteps, userStartRow, userStartCol;

          cout << "Please enter a value between 2 and 100 for rows." << endl;
          cin >> userRows;

          //Input Validation to determine if the user entered a correct value
          while (userRows > 100 || userRows < 2 || cin.get() != '\n')
          {
               cin.clear();
               cin.ignore(256, '\n');
               cout << "Please try again with a value between 2 and 100." << endl;
               cin >> userRows;
          }

          cout << "Please enter a value between 2 and 100 for columns." << endl;
          cin >> userCols;

          //Input Validation to determine if the user entered the correct value
          while (userCols > 100 || userCols < 2 || cin.get() != '\n')
          {
               cin.clear();
               cin.ignore(256, '\n');
               cout << "Please try again with a value between 2 and 100." << endl;
               cin >> userCols;
          }

          cout << "Please enter the number of steps you would like to run." << endl;
          cin >> userSteps;

          //Input Validation to see if the user entered the right values for steps
          while (userSteps < 1 || cin.get() != '\n')
          {
               cin.clear();
               cin.ignore(256, '\n');
               cout << "Please try again for the number of steps." << endl;
               cin >> userSteps;
          }

          cout << "Choose a row for the ant to start on." << endl;
          cin >> userStartRow;

          //Input validation to see if the user entered a correct starting point
          while (userStartRow > userRows || userStartRow < 1 || cin.get() != '\n')
          {
               cin.clear();
               cin.ignore(256, '\n');
               cout << "Please try again for the row to start at." << endl;
               cin >> userStartRow;
          }

          cout << "Choose a column for the ant to start on." << endl;
          cin >> userStartCol;

          //Input validation to determine if the user entered a correct starting point
          while (userStartCol > userCols || userStartCol < 0 || cin.get() != '\n')
          {
               cin.clear();
               cin.ignore(256, '\n');
               cout << "Please try again for the column to start at." << endl;
               cin >> userStartCol;
          }

          char ** board;
          board = new char*[userRows];
          for (int i = 0; i < userRows; i++)
          {
               board[i] = new char[userCols];
          }

          Ant ant(board, userStartRow, userStartCol, userRows, userCols);

          ant.makeMove(board, userStartRow, userStartCol, userSteps);

          for (int i = 0; i < userRows; i++)
          {
               delete[] board[i];
          }
          delete[] board;

          int userInput = menu();

          //If the user entered 2, the program will quit now
          if (userInput == 2)
          {
               return 0;
          }
     }

     //If the user entered 2, the program will quit from the start
     if (userInput == 2)
     {
          return 0;
     }

     return 0;
}