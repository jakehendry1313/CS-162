/**************************************************************************
** Program name: Project 3  - menu.cpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This is cpp file that will determine what the user chooses
**               and will return that choice to start the program.
****************************************************************************/
#include "menu.hpp"
#include "inputVerification.cpp"
#include <iostream>
#include <string>

/*********************************************************************
* This function will add the choices to choose into the program.
*********************************************************************/
void userMenu::add_choice(std::string option) 
{
     choice.push_back(option);
}

/*********************************************************************
* This function will print the menu to the screen for the user to
* look at and choose from.
*********************************************************************/
void userMenu::printMenu() 
{
     for (size_t i = 0; i < choice.size(); ++i)
          std::cout << " " << i + 1 << ".  " << choice[i] << "\n";
}

/*********************************************************************
* This is the function that will determine what the user chooses 
* from the list of options and validates the user's input.
*********************************************************************/
int userMenu::makeChoice() 
{
     printMenu();

     int choiceSize = choice.size() + 1;

     std::string varString = "Please select a valid option.\n";

     SafeInput <int>(selectedChoice,
          [=](int Input) -> bool {
          return (!std::cin.fail() && (std::cin.peek() == EOF || std::cin.peek() == '\n') && (Input > 0 && Input < choiceSize));
     }, varString);
     return selectedChoice;
}