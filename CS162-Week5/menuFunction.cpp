/**************************************************************************
** Program name: Lab 5  - menuFunction.cpp
** Author:       Jacob Hendry
** Date:         5/5/2019
** Description:  This file will include the menu function that will start
**               at the beginning of the program to determine what the
**               user would like to do (use one of the functions or quit).
****************************************************************************/

#include <iostream>
#include <string>
#include "menuFunction.hpp"
#include "recursiveFunctions.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int menu()
{
          // This variable will be used for the user's choice
          int userChoice;

          //This bool variable will determine if the program will quit or not
          bool quit = false;

          do
          {

               //The menu function will give 4 options to choose from in the beginning
               cout << "----------------MAIN MENU------------------" << endl;
               cout << endl;
               cout << "Please choose one of the following options: " << endl;
               cout << endl;
               cout << "Option 1. Reverse a string using a recursive function." << endl;
               cout << "Option 2. Find the sum of an array with a recursive function." << endl;
               cout << "Option 3. Find the triangular number of an integer N." << endl;
               cout << "Option 4. Quit the Program." << endl;
               cout << endl;
               cin >> userChoice;

               //Input Validation to determine if the user's choice is valid
                while (userChoice > 4 || userChoice < 1 || cin.get() != '\n')
               {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Please try again" << endl;
                    cout << "Enter a valid choice between 1 and 4" << endl;
                    cin >> userChoice;
               }

               //This while statement will reverse a string inputted by the user
               if (userChoice == 1)
               {
                    string userString;

                    cout << "Please enter a string" << endl;
                    getline(cin, userString);

                    cout << reverseStr(userString) << endl;
                    cout << endl;
               }


               //This while statement will start the array sum function
               else if (userChoice == 2)
               {
                    int userNumbers, userInputNum, *arrayPtr;

                    cout << "How many numbers would you like in the array?" << endl;
                    cin >> userNumbers;

                    //Input Validation to see if the user entered the right value for numbers
                    while (userNumbers <= 0 || cin.get() != '\n')
                    {
                         cin.clear();
                         cin.ignore(256, '\n');
                         cout << "ERROR!" << endl;
                         cout << "Please try again with numbers above 0 only." << endl;
                         cin >> userNumbers;
                    }

                    arrayPtr = new int[userNumbers];

                    for (int i = 0; i < userNumbers; i++)
                    {
                         cout << "Enter Integer: " << endl;
                         cin >> userInputNum;

                         // Input Validation to see if the user entered the correct variable
                         while (cin.get() != '\n')
                         {
                              cin.clear();
                              cin.ignore(256, '\n');
                              cout << "ERROR!" << endl;
                              cout << "Please try again with numbers only." << endl;
                              cin >> userInputNum;
                         }

                         //The user's input will be used to determine the size of an array
                         arrayPtr[i] = userInputNum;
                    }
                  
                    cout << endl << "The sum of the numbers is ";
                    cout << arraySum(arrayPtr, userNumbers) << "." << endl;
                    cout << endl;

                    //Delete the dynamically allocated memory 
                    delete[] arrayPtr;
               }

               //This while statement will use the triangular number function
               else if (userChoice == 3)
               {
                    int userTriNum;

                    cout << endl << "Please input a number you like to find the";
                    cout << " triangular number of." << endl;
                    cin >> userTriNum;

                    //Input Validation to see if the user entered the right value for number
                    while (userTriNum < 0 || cin.get() != '\n')
                    {
                         cin.clear();
                         cin.ignore(256, '\n');
                         cout << "ERROR!" << endl;
                         cout << "Please try again with numbers above 0 only." << endl;
                         cin >> userTriNum;
                    }
                    //The triangular number will be displayed here using the triangular function
                    cout << "N: " << triangleNum(userTriNum) << endl;
                    cout << endl;
               }

               //This while statement will quit the program
               else if (userChoice == 4)
               {
                    quit = true;
               }

          } while (quit == false);
    
     return 0;
}