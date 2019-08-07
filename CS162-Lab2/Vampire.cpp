/***************************************************************************
** Program name: Project 3  - Vampire.cpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This cpp file will implement the prototypes from the header
**               file for the vampire header file. It will hold the functions
**               for the die roll and the strength of vampire.
****************************************************************************/
#include "Vampire.hpp"
#include <ctime>
#include <stdlib.h>

/*********************************************************************
* This is the default constructor that will hold all of the vampire
* armor, strength, name, and the die roll.
*********************************************************************/
Vampire::Vampire()
{
     name = "Vampire";
     armor = 1;
     strength = 18;
     dieNumAttack = 1;
     dieSidesAttack = 12;
     specialAttack = "";
     dieNumDefense = 1;
     dieSidesDefense = 6;
}

/*********************************************************************
* This is the attack roll function that will return the amount of 
* the die that will determine what the amount of an attack the
* vampire will produce.
*********************************************************************/
int Vampire::attack_roll()
{
     this->specialAttack = "";

     return die_roll(this->dieNumAttack, this->dieSidesAttack);
}

/*********************************************************************
*This is the defense roll function that will return the amount of 
* the die that will determine what the amount of an defense of
* medusa will produce.
*********************************************************************/
int Vampire::defense_roll(int attack)
{
     this->specialAttack = "";

     if ((rand() % 2) > 0)
     {
          this->specialAttack = "CHARM";
          return 0;
     }
     return Characters::defense_roll(attack);
}

/*********************************************************************
* This strength recovery function will return the strength of 18 for
* the vampire.
*********************************************************************/
void Vampire::recover_strength()
{
     strength = 18;
}

/*********************************************************************
* This is the desctrutor for the vampire that will destroy the
* new constructor to use again after the first time.
*********************************************************************/
Vampire::~Vampire() {}