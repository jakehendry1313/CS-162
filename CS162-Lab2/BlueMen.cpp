/**************************************************************************
** Program name: Project 3  - BlueMen.cpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This cpp file will implement the prototypes from the header
**               file for the bluemen header file. It will hold the functions
**               for the die roll and the strength of bluemen.
****************************************************************************/
#include "BlueMen.hpp"

/*********************************************************************
*This is the default constructor that will hold all of the bluemens
* armor, strength, name, and the die roll.
*********************************************************************/
BlueMen::BlueMen() {
     armor = 3;
     strength = 12;
     name = "Blue Men";
     dieNumAttack = 2;
     dieSidesAttack = 10;
     dieSidesDefense = 6;
     specialAttack = "";
}

/*********************************************************************
* This is the attack roll function that will return the amount of 
* the die that will determine what the amount of an attack the
* bluemen will produce.
*********************************************************************/
int BlueMen::attack_roll() 
{
     return die_roll(this->dieNumAttack, this->dieSidesAttack);
}

/*********************************************************************
** Function: BlueMen::defense_roll()
** Description: Defense roll of the dice for the BlueMen. Passes the
**				defense die to the die_roll function to get the defense
**				value.
** Parameters:	N/A
** Pre-Conditions: N/A
** Post-Conditions: Returns an int from the die_roll function.
*********************************************************************/
int BlueMen::defense_roll(int attack) 
{
     if (this->strength > 8)
     {
          this->dieNumDefense = 3;
     }

     else if (this->strength > 4)
     {
          this->dieNumDefense = 2;
     }

     else if (this->strength > 0)
     {
          this->dieNumDefense = 1;
     }

     return Characters::defense_roll(attack);
}

/*********************************************************************
* This strength recovery function will return the strength of 12 for
* the bluemen.
*********************************************************************/
void BlueMen::recover_strength() 
{
     strength = 12;
}

/*********************************************************************
* This is the desctrutor for the bluemen that will destroy the
* new constructor to use again after the first time.
*********************************************************************/
BlueMen::~BlueMen() {}