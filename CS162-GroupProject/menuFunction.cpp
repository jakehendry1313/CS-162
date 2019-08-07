/**************************************************************************
** Program name: Group 13 Project  - menuFunction.cpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This file will include the menu function that will start
**               at the beginning of the program to determine what the
**               user would like to do (either start the program or quit).
****************************************************************************/

#include <iostream>
#include "menuFunction.hpp"

using std::cout;
using std::cin;
using std::endl;

int menu()
{
     //This variable will be used for the user's choice
     int userChoice;

     //The menu function will give the 3 options to choose from
     cout << "Welcome to the Predator-Prey Game!" << endl;
     cout << "----------------------------------" << endl;
     cout << "Please choose one of the following: " << endl;
     cout << "--1. Play the game randomly" << endl;
     cout << "--2. Play a custom game" << endl;
     cout << "--3. Quit the game" << endl;
     cin >> userChoice;

     //Input Validation to determine if the user's choice is valid
     while (userChoice > 3 || userChoice < 1 || cin.get() != '\n')
     {
          cin.clear();
          cin.ignore(256, '\n');
          cout << "Please try again" << endl;
          cout << "Enter a valid choice: 1, 2 or 3" << endl;
          cin >> userChoice;
     }

     //This while statement will return to start the program in random mode
     while (userChoice == 1)
     {
          int userSteps;

          cout << "Please enter the number of steps you would like to run." << endl;
          cin >> userSteps;

          //Input Validation to see if the user entered the right value for steps
          while (userSteps < 1 || cin.get() != '\n')
          {
               cin.clear();
               cin.ignore(256, '\n');
               cout << "Please try again." << endl;
               cout << "Please use numbers greater than 0 only." << endl;
               cin >> userSteps;
          }
          return 1;
     }

     //This while statement will return to start a custom program
     while (userChoice == 2)
     {
          int userRows, userCols, userSteps, userAnts, userDoodlebugs;

          cout << "Please enter the number of steps you would like to run." << endl;
          cin >> userSteps;

          //Input Validation to see if the user entered the right value for steps
          while (userSteps < 1 || cin.get() != '\n')
          {
               cin.clear();
               cin.ignore(256, '\n');
               cout << "ERROR!" << endl;
               cout << "Please try again for the number of steps." << endl;
               cin >> userSteps;
          }

          cout << "Please enter a value for the number of rows." << endl;
          cin >> userRows;

          //Input Validation to determine if the user entered a correct value for rows
          while (userRows > 100000 || userRows < 1 || cin.get() != '\n')
          {
               cin.clear();
               cin.ignore(256, '\n');
               cout << "ERROR!" << endl;
               cout << "Please try again with numbers above 0 only" << endl;
               cin >> userRows;
          }

          cout << "Please enter a value for the number of columns." << endl;
          cin >> userCols;

          //Input Validation to determine if the user entered the correct value for columns
          while (userCols > 10000 || userCols < 1 || cin.get() != '\n')
          {
               cin.clear();
               cin.ignore(256, '\n');
               cout << "ERROR!" << endl;
               cout << "Please try again with numbers above 0 only" << endl;
               cin >> userCols;
          }

          cout << "Please enter a number of ants you would like to start with." << endl;
          cin >> userAnts;

          //Input validation to see if the user entered a correct value for ants
          while (userAnts > userRows || userAnts < 0 || cin.get() != '\n')
          {
               cin.clear();
               cin.ignore(256, '\n');
               cout << "ERROR!" << endl;
               cout << "Please try again for the amount of ants used." << endl;
               cin >> userAnts;
          }

          cout << " Please enter a number of doodlebugs to start with." << endl;
          cin >> userDoodlebugs;

          //Input validation to determine if the user entered a correct value for doodlebugs
          while (userDoodlebugs > userCols || userDoodlebugs < 0 || cin.get() != '\n')
          {
               cin.clear();
               cin.ignore(256, '\n');
               cout << "ERROR!" << endl;
               cout << "Please try again for the column to start at." << endl;
               cin >> userDoodlebugs;
          }
          return 2;
     }

     //THis while statement will return to quit the program
     while (userChoice == 3)
     {
          return 3;
     }

     return 0;
}