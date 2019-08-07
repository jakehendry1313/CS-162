/**************************************************************************
** Program name: Project 3  - BlueMen.cpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This cpp file will implement the prototypes from the header
**               file for the character header file. It will be used as a 
**               base class to be implemented in each of the characters.
****************************************************************************/
#include "Characters.hpp"
#include <string>
#include <ctime>

using std::string;

/*********************************************************************
* This is the default constructor that will hold all of the characters
* armor, strength, name, die roll, and special attack to use.
*********************************************************************/
Characters::Characters()
{
     strength = 0;
     armor = 0;
     defPoints = 0;
     name = "";
     specialAttack = "";
     dieNumAttack = 0;
     dieSidesAttack = 0;
     dieNumDefense = 0;
     dieSidesDefense = 0;
     std::srand(static_cast<unsigned int>(time(0)));
}

/*********************************************************************
* This getter function will be used to grab the name of the character
* that was chosen and return it to the main function.
*********************************************************************/
std::string Characters::get_name()
{
     return name;
}

/*********************************************************************
* This getter function will be used to return the strength of the 
* character being used to determine whether or not has won or not.
*********************************************************************/
int Characters::get_strength()
{
     return strength;
}

/*********************************************************************
* This getter function will return the amount of armor the selected
* character has to use for the battle.
*********************************************************************/
int Characters::get_armor()
{
     return armor;
}

/*********************************************************************
* This getter function will return the amount of points the defense
* of a character received during the fight.
*********************************************************************/
int Characters::get_defPoints()
{
     return defPoints;
}

/*********************************************************************
* This getter function will return the special attack the character
* can use if it is possible.
*********************************************************************/
std::string Characters::get_special()
{
     return specialAttack;
}

/*********************************************************************
* This function will determine the amount of damage each character
* has taken during the battle. It will return the amount of damage
* until their damage is down to 0 which would then be subtracted by
* the strength.
*********************************************************************/
int Characters::defense_roll(int attack)
{
     defPoints = die_roll(this->dieNumDefense, this->dieSidesDefense);

     int total_pain = attack - (defPoints + armor);

     if (total_pain > 0)
     {
          strength = strength - total_pain;
          return total_pain;
     }

     return 0;
}

/*********************************************************************
* This function will determine to roll the die based on the defense
* or the attack for the character's turn.
*********************************************************************/
int Characters::die_roll(int dieNum, int dieSides)
{
     int dieSum = 0;

     for (int i = 0; i < dieNum; i++)
     {
          dieSum = dieSum + rand() % dieSides + 1;
     }
     return dieSum;
}

/*********************************************************************
* This function will determine if the character has been defeated if
* the strength has reached 0 or below.
*********************************************************************/
bool Characters::defeated()
{
     return strength <= 0;
}

/*********************************************************************
*This is the desctrutor for the character class that will destroy the
* new constructor to use again after the first time.
*********************************************************************/
Characters::~Characters() {}