/**************************************************************************
** Program name: Project 3  - Medusa.cpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This cpp file will implement the prototypes from the header
**               file for the Medusa header file. It will hold the functions
**               for the die roll and the strength of medusa.
****************************************************************************/
#include "Medusa.hpp"

/*********************************************************************
* This is the default constructor that will hold all of medusa's
* armor, strength, name, and the die roll.
*********************************************************************/
Medusa::Medusa() 
{
     armor = 3;
     strength = 8;
     name = "Medusa";
     dieNumAttack = 2;
     dieNumDefense = 1;
     dieSidesAttack = dieSidesDefense = 6;
}

/*********************************************************************
* This is the attack roll function that will return the amount of 
* the die that will determine what the amount of an attack the
* medusa will produce.
*********************************************************************/
int Medusa::attack_roll()
{
     this->specialAttack = "";
     int dieSum = die_roll(this->dieNumAttack, this->dieSidesAttack);

     if (dieSum == 12) 
     {
          this->specialAttack = "GLARE";
     }
     return dieSum;
}

/*********************************************************************
* This is the defense roll function that will return the amount of 
* the die that will determine what the amount of an defense of
* medusa will produce.
*********************************************************************/
int Medusa::defense_roll(int attack)
{
     this->specialAttack = "";
     return Characters::defense_roll(attack);
}

/*********************************************************************
* This strength recovery function will return the strength of 8 for
* medusa.
*********************************************************************/
void Medusa::recover_strength()
{
     strength = 8;
}

/*********************************************************************
* This is the desctrutor for Medusa that will destroy the constructor 
* to use again after the first time.
*********************************************************************/
Medusa::~Medusa() {}