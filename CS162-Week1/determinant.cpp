/***************************************************************************
** Program name: Lab 1 - determinant.cpp
** Author:       Jacob Hendry 
** Date:         4/7/2019
** Description:  This file will hold the funcion call determinant that will
**               determine the matrix that was chosen by the user. Once its
**               determined it would calculate the determinant based on the
**               matrix size and will then return it to the main function.
***************************************************************************/
#include "readMatrix.hpp"
#include "determinant.hpp"

int determinant(int** matrix, int size) 
{
	int deterNum;

	//This if statement will be used for the 2x2 matrix
	if (size == 2) 
	{
       int a = matrix[0][0];
       int b = matrix[0][1];
       int c = matrix[1][0];
       int d = matrix[1][1];

       deterNum = (a*d) - (b*c);
     }

	 
     else 
	 {
       int a = matrix[0][0];
       int b = matrix[0][1];
       int c = matrix[0][2];
       int d = matrix[1][0];
       int e = matrix[1][1];
       int f = matrix[1][2];
       int g = matrix[2][0];
       int h = matrix[2][1];
       int i = matrix[2][2];

       deterNum = a*(e*i - f*h) - b*(d*i - f*g) + c*(d*h - e*g);
     }
     return deterNum;
}
