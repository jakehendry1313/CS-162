/********************************************************************************
** Program name: Project 3  - HarryPotter.cpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This cpp file will implement the prototypes from the header
**               file for the harry potter header file. It will hold the functions
**               for the die roll and the strength of barbarian.
****************************************************************************/
#include "HarryPotter.hpp"

/*********************************************************************
* This constructor will hold every variable needed to use the new
* character harry potter.
*********************************************************************/
HarryPotter::HarryPotter() {
     armor = 0;
     strength = 10;
     harryLives = 1;
     name = "Harry Potter";
     dieNumAttack = dieNumDefense = 2;
     dieSidesAttack = dieSidesDefense = 6;
     specialAttack = "";
}

/*********************************************************************
*This is the default constructor that will hold all of harry potter's
* armor, strength, name, and the die roll.
*********************************************************************/
int HarryPotter::attack_roll()
{
     this->specialAttack = "";

     return die_roll(this->dieNumAttack, this->dieSidesAttack);
}

/*********************************************************************
* This function will determine the defense's roll amount to return to
* the battle and do some damage.
*********************************************************************/
int HarryPotter::defense_roll(int attack)
{
     int damage = Characters::defense_roll(attack);

     if (this->harryLives > 0 && this->defeated()) 
     {
          strength = 20;
          this->specialAttack = "HOGWARTS";
          this->harryLives--;
     }
     return damage;
}

/*********************************************************************
* This strength recovery function will return the strength of 10 for
* harry potter for each of his lives. 
*********************************************************************/
void HarryPotter::recover_strength()
{
     strength = 10;
     this->harryLives = 1;
}

/********************************************************************
* This is the destructor that will delete the new harry potter 
* when it is all done being used.
********************************************************************/
HarryPotter::~HarryPotter() {}