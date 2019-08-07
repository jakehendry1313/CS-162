/**************************************************************************
** Program name: Project 3  - inputVerification.cpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This is the verification for the input by the user to see
**               if it is valid input or not. It will implement the class
**               InputType to determine if the input is valid. 
****************************************************************************/
#include <functional>
#include <limits>
#include <cctype>
#include <iostream>
#include <string>
template <class InputType>

/***********************************************************************
* This function will be used determine if the user inputted the correct
* input for the program to use.
***********************************************************************/
void SafeInput(InputType & InputVar, std::function <bool(InputType &)> Predicate, std::string s) 
{
     for (;; ) 
     {
          std::cin >> InputVar;

          if (std::cin.good() && Predicate(InputVar)) return;

          std::cerr << s;

          std::cin.clear();
          std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
     }
}