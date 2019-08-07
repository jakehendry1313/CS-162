/**************************************************************************
** Program name: Project 3  - Medusa.hpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This is the header file for Vampire. It will hold the
**               prototypes for the constructor, attack rolls, strength, and
**               the destructor as well.
****************************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Characters.hpp"

class Vampire :public Characters 
{
public:
     Vampire();
     virtual int attack_roll();
     virtual int defense_roll(int);
     virtual void recover_strength();
     virtual ~Vampire();
};

#endif