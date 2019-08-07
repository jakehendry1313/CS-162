/**************************************************************************
** Program name: Lab 7  - menu.cpp
** Author:       Jacob Hendry
** Date:         5/19/2019
** Description:  This file will implement the menu function. The user will
**               have 5 choices to choose from. Some of the options include
**               exiting the program, adding an integer to the back of the
**               queue, return the whole queue or the front node.
****************************************************************************/
#include "QueueClass.hpp"
#include "menu.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int menu()
{
     Queue list;

     // This variable will be used for the user's choice
     int userChoice;

     //This bool variable will determine if the program will quit or not
     bool quit = false;

     cout << "Welcome to my Queue!" << endl;

     do
     {
          //The menu function will give 5 options to choose from in the beginning
          cout << endl;
          cout << "Please choose one of the following options: " << endl;
          cout << endl;
          cout << "1. Enter a value to be added to the back of queue." << endl;
          cout << "2. Display first node (front) value." << endl;
          cout << "3. Remove first node (front) value." << endl;
          cout << "4. Display the queue contents." << endl;
          cout << "5. Exit the program." << endl;
          cout << endl;
          cout << "Your choice: ";
          cin >> userChoice;
          cout << endl;

          //Input Validation to determine if the user's choice is valid
          while (userChoice > 8 || userChoice < 1 || cin.get() != '\n')
          {
               cin.clear();
               cin.ignore(256, '\n');
               cout << "INVALID INPUT!" << endl;
               cout << "Only enter numbers between 1 and 8." << endl;
               cout << "Your choice: ";
               cin >> userChoice;
               cout << endl;
          }


          //This else if statement will add an integer to the back
          if (userChoice == 1)
          {
               int value;

               cout << "Please enter a positive integer: ";
               cin >> value;
               cout << endl;

               //Input Validation to see if the user entered the right value for numbers
               while (value < 0 || cin.get() != '\n')
               {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "ERROR!" << endl;
                    cout << "Please try again with a number as 0 or above only." << endl;
                    cout << "Input here: ";
                    cin >> value;
                    cout << endl;
               }

               list.addBack(value);
          }


          //This else if statement will return the head value
          else if (userChoice == 2)
          {
               int valueAtFront = list.getFront();

               if (valueAtFront == -1)
               {
                    cout << "The queue is empty!" << endl;
               }

               else
               {
                    cout << valueAtFront << endl;
               }
          }

          //This else if statement will delete the head
          else if (userChoice == 3)
          {
               list.removeFront();

               if (NULL)
               {
                    cout << "The queue is empty!" << endl;
               }

          }

          //This else if statement will print the queue
          else if (userChoice == 4)
          {
               list.printQueue();
          }

          //This else if statement will exit the program
          else if (userChoice == 5)
          {
               quit = true;
          }

     } while (quit == false);

     return 0;
}