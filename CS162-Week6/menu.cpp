/**************************************************************************
** Program name: Lab 6  - menu.cpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This file will implement the menu function. The user will
**               have 8 choices to choose from. Some of the options include
**               exiting the program, printing the head or tail value, or
**               adding/deleting a head or tail in the node.
****************************************************************************/
#include "doubleLinkedList.hpp"
#include "menu.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int menu()
{
     LinkedList list;

     // This variable will be used for the user's choice
     int userChoice;

     //This bool variable will determine if the program will quit or not
     bool quit = false;

     cout << "Welcome to my Linking List!" << endl;

     do
     {
          //The menu function will give 8 options to choose from in the beginning
          cout << endl;
          cout << "Please choose one of the following options: " << endl;
          cout << endl;
          cout << "1. Add a new node to the head." << endl;
          cout << "2. Add a new node to the tail." << endl;
          cout << "3. Delete the first node in the list." << endl;
          cout << "4. Delete the last node in the list." << endl;
          cout << "5. Traverse the list reversely" << endl;
          cout << "6. Print the Head value." << endl;
          cout << "7. Print the Tail value." << endl;
          cout << "8. Exit the program." << endl;
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

          //This if statement will add an integer to a head 
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

               list.addFront(value);
          }


          //This else if statement will add an integer to the tail
          else if (userChoice == 2)
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

          //This else if statement will delete the head
          else if (userChoice == 3)
          {
               int value = list.deleteFront();

               if (value == -1)
               {
                    cout << "The list is empty!" << endl;
               }

          }

          //This else if statement will delete the tail
          else if (userChoice == 4)
          {
               int value = list.deleteBack();

               if (value == -1)
               {
                    cout << "THe list is empty!" << endl;
               }

          }

          //This else if statement will reverse the order of the node
          else if (userChoice == 5)
          {
               list.traverseReverse();
          }

          //This else if statement will return the head value
          else if (userChoice == 6)
          {
               int valueAtFront = list.getAtHead();

               if (valueAtFront == -1)
               {
                    cout << "The list is empty!" << endl;
               }

               else
               {
                    cout << "The value of the head is: " << valueAtFront << endl;
               }
          }

          //This else if statement will return the tail value
          else if (userChoice == 7)
          {
               int valueAtFront = list.getAtTail();

               if (valueAtFront == -1)
               {
                    cout << "The list is empty!" << endl;
               }

               else
               {
                    cout << "The value of the tail is: " << valueAtFront << endl;
               }
          }

          //This else if statement will exit the program
          else if (userChoice == 8)
          {
               quit = true;
          }

     } while (quit == false);

     return 0;
}