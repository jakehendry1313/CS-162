/**************************************************************************
** Program name: Lab 1 - readMatrix.cpp
** Author:       Jacob Hendry
** Date:         4/7/2019
** Description:  This file will hold the void function called readMatrix
**               that will ask for the user to enter a specific amount of
**               integers based on the choice of the matrix. It should be
**               either 4 or 9 integers and shouldn't return anything.
**************************************************************************/
#include <iostream>
#include "readMatrix.hpp"

using std::cout;
using std::cin;
using std::endl;


void readMatrix(int** matrix, int size) {
     cout << "Please enter 4 or 9 integers " << endl;

	 //This for statement will list out the users inputs
     for (int i = 0; i < size; i++) 
	 {
          for (int j = 0; j < size; j++) 
		  {
               cin >> matrix[i][j];
          }
		  cout << "\n";
     }
}
