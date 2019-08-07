#include <queue>
#include <stack>
#include <time.h>
#include<iostream>
#include <string>
#include <vector>
#include "Queue.hpp"
using namespace std;


int RandomNumber()
{
     srand(time(NULL));
     int N = rand() % 1000 + 1;
     return N;
}



     int turn(int percent)
     {
          int N = RandomNumber();
          if (N <= percent)
          {
               return N;
          }
          else return -1;
     }

     void runSimulation(int intIn1, int intIn2, int intIn3)
     {
          cout << endl;
          queue<int> myQueue;
          for (int i = 0; i < intIn3; i++)
          {
               int addValue = turn(intIn1);
               if (addValue != -1) myQueue.push(addValue);
               int removeValue = turn(intIn2);
               if (removeValue != -1)
               {
                    if (myQueue.size() != 0) myQueue.pop();
               }
          }
          cout << "**********************" << endl;
          cout << "Simulation rounds are complete." << endl;
          cout << endl;
          cout << "User chosen odds of ADDING an element in each round: " << intIn1 << "%" << endl;
          cout << "User chosen odds of REMOVING an element in each round: " << intIn2 << "%" << endl;
          cout << "User chosen rounds to run: " << intIn3 << endl;
          cout << endl;
          cout << "Number of items in the queue at end: " << myQueue.size() << endl;
          cout << endl;
          myQueue = queue<int>();

     }


void StackGame()
{

     stack<char, vector<char> > palin;
     string str, reverse;

     cout << "Enter a string to make it palindrome: " << endl;
     getline(cin, str);

     for (int i = 0; i < str.length(); i++)
     {
          palin.push(str[i]);
     }

     for (int i = 0; i < str.length(); i++)
     {
          reverse += palin.top();
          palin.pop();
     }

     cout << "Palindrome: " << str << reverse << endl;
     cout << endl;
}

int main()
{
     // This variable will be used for the user's choice
     int userChoice;

     //This bool variable will determine if the program will quit or not
     bool quit = false;

     cout << "Welcome to my Lab 9!" << endl;

     do
     {
          //The menu function will give 5 options to choose from in the beginning
          cout << endl;
          cout << "Please choose one of the following options: " << endl;
          cout << endl;
          cout << "1. Queue" << endl;
          cout << "2. Stack" << endl;
          cout << "3. Exit" << endl;
          cout << endl;
          cout << "Your choice: ";
          cin >> userChoice;
          cout << endl;

          //Input Validation to determine if the user's choice is valid
          while (userChoice > 3 || userChoice < 1 || cin.get() != '\n')
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
               queue <int> Q;
               Q.push(10);
               Q.push(20);
               Q.push(30);
               cout << "Queue size before printing the elements: " << Q.size() << endl;
               cout << "Queue element are... " << endl;
               QueueGame(Q);
               cout << "Queue size after printing the elements: " << Q.size() << endl;
          }

          //This else if statement will return the head value
          else if (userChoice == 2)
          {
               StackGame();
          }

          //This else if statement will exit the program
          else if (userChoice == 3)
          {
               quit = true;
          }

     } while (quit == false);

     return 0;
}