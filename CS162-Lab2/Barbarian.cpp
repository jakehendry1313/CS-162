/********************************************************************************
** Program name: Project 3  - Barbarian.cpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This cpp file will implement the prototypes from the header
**               file for the barbarian header file. It will hold the functions
**               for the die roll and the strength of barbarian.
****************************************************************************/
#include "Barbarian.hpp"

/*********************************************************************
* This is the default constructor that will hold all of the barbarians
* armor, strength, name, and the die roll.
*********************************************************************/
Barbarian::Barbarian() 
{
     armor = 0;
     strength = 12;
     name = "Barbarian";
     dieNumAttack = 2;
     dieSidesAttack = 6;
     dieNumDefense = 2;
     dieSidesDefense = 6;
     this->specialAttack = "";
}

/*********************************************************************
* This is the attack roll function that will return the amount of 
* the die that will determine what the amount of an attack the
* barbarian will produce.
*********************************************************************/
int Barbarian::attack_roll() 
{
     return die_roll(this->dieNumAttack, this->dieSidesAttack);
}

/*********************************************************************
* This strength recovery function will return the strength of 12 for
* the barbarian. 
*********************************************************************/
void Barbarian::recover_strength() 
{
     strength = 12;
}

/*********************************************************************
* This is the desctrutor for the Barbarian that will destroy the
* new constructor to use again after the first time.
*********************************************************************/
Barbarian::~Barbarian() {}