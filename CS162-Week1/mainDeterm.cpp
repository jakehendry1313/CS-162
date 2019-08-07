/***************************************************************************
** Program name: Lab 1 - mainDeterm.cpp
** Name:         Jacob Hendry
** Date:         4/7/2019
** Description:  This file will hold the main function that will execute the
**               entire program and includes the readMatrix file and the 
**               determinant file to determine the determinant and displays
**               the matrix chosen from the user.
***************************************************************************/
#include <iostream>
#include "readMatrix.hpp"
#include "determinant.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() 
{
     cout << "Please select the matrix size your chose:" << endl;
     cout << "(1): 2x2 matrix" << endl;
     cout << "(2): 3x3 matrix" << endl;

     int selection;       //Stores matrix size selection
     cin >> selection;

     int size;   //Size of matrix

     //Determines the user's selection
     if (selection == 1) {
          size = 2;
     }
     else if (selection == 2) {
          size = 3;
     }
     else {
          cout << "Please enter another selection" << endl;
          return 0;
     }

     //Pointer array being initialized
     int** matrix = new int*[size];
     for (int i = 0; i < size; i++) {
          matrix[i] = new int[size];
     }
	
	//The program will use readMatrix file to determine the matrix
     readMatrix(matrix, size);

	//The calDeter variable will the hold the calculated determinant
     int calDeter = determinant(matrix, size);

     cout << "Here is the matrix you chose:" << endl;
     for (int row = 0; row < size; row++) 
	 {
          for (int col = 0; col < size; col++) 
		  {
               cout << matrix[row][col] << "\t";
          }
		  cout << "\n";
     }

     //This for statement will delet thee matrix
     for (int i = 0; i < size; i++) {
          delete[] matrix[i];
     }
     delete[] matrix;

     cout << "The determinant of your matrix is: " << calDeter << endl;

     return 0;
}
