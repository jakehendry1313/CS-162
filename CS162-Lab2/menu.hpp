/**************************************************************************
** Program name: Project 3  - menu.hpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This is the header file for the menu function. It will hold 
**               the the prototypes for the menu function such as adding the
**               possible choices, printing the menu, and determining if the
**               user input a valid choice.
****************************************************************************/
#ifndef USERMENU_HPP
#define USERMENU_HPP
#include <vector>
#include <string>

class userMenu
{
private:
     std::vector<std::string> choice;
     int selectedChoice;

public:
     void add_choice(std::string);
     void printMenu();
     int makeChoice();
};

#endif