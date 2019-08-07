/**************************************************************************
** Program name: Lab 5  - recursiveFunctions.cpp
** Author:       Jacob Hendry
** Date:         5/5/2019
** Description:  This file will include three different recursive functions.
**               The first function prints a string backwards, the second
**               function adds the sum of an array, and the third function
**               calculates the triangular number of an integer (N).
****************************************************************************/

#include <iostream>
#include "recursiveFunctions.hpp"

using std::string;
using std::cout;
using std::endl;

/*********************************************************************
*                   reverseStr Function
* This function will use recursion to determine what the user's string
* input size is and what case to use based on that size. If the length
* this 0, it will return that length, but if it's longer it will
* start to reverse each letter/symbol/number of the string.
*********************************************************************/
string reverseStr(string inputStr) 
{
     //BASE CASE
     if (inputStr.length() == 0)
          return inputStr;

     //RECURSION CASE
     else
     {
          string old = inputStr.substr(0, 1);
          string newstr = inputStr.substr(1, (inputStr.length() - 1));
          return reverseStr(newstr) + old;
     }
}


/********************************************************************
*                    arraySum Function
* This recursive function will detrmine the sum of an array based on
* the user's input for the size and all the numbers within the array.
* It will determine what case to use based on the size of the array.
********************************************************************/
int arraySum(int* a, int s)
{
     //BASE CASE
     if (s <= 0)
     {
          return 0;
     }

     //RECURSION CASE
     else
     {
          return arraySum(a, s - 1) + a[s - 1];
     }
}

/*****************************************************************
*                        triangleNum Function
* This recursive functino will determine whether or not to use
* the base case or the recursion based on the user's inputted 
* number. If the user number isn't 0, the recursion will take
* place to determine the triangular number of an integer.
****************************************************************/
int  triangleNum(int s)
{
     //BASE CASE
     if (s == 0)
     {
          return 0;
     }

     //RECURSION CASE
     else
     {
          return triangleNum(s - 1) + s;
     }
}
