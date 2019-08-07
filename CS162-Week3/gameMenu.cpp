/*/**************************************************************************
** Program name: Lab 3 - gameMenu.cpp
** Author:       Jacob Hendry
** Date:         4/21/2019
** Description:  This is the game menu file that will hold the menu function
                 for the user to choose whether to start the game or quit.
****************************************************************************/
/*
#include <iostream>
#include "gameMenu.hpp"

using std::cout;
using std::cin;
using std::endl;

int menu()
{
     //This variable will be used for the user's choice
     int userChoice;

     //The program will give the 2 options to choose from
     cout << "Please choose one of the following: " << endl;
     cout << "1. Play the game, WAR!" << endl;
     cout << "2. Quit game" << endl;
     cin >> userChoice;

     //Input Validation to determine if the user's choice is valid
     while (userChoice > 2 || userChoice < 1 || cin.get() != '\n')
     {
          cin.clear();
          cin.ignore(256, '\n');
          cout << "Please try again" << endl;
          cout << "Enter a valid choice: 1 or 2" << endl;
          cin >> userChoice;
     }

     //This while statement will return to start the program
     while (userChoice == 1)
     {
          return 1;
     }

     //THis while statement will return to quit the program
     while (userChoice == 2)
     {
          return 2;
     }

     return 0;
}
*/