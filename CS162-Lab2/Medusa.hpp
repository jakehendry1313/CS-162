/**************************************************************************
** Program name: Project 3  - Medusa.hpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This is the header file for Medusa. It will hold the
**               prototypes for the constructor, attack rolls, strength, and
**               the destructor as well.
****************************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Characters.hpp"

class Medusa : public Characters 
{
public:
     Medusa();
     virtual int attack_roll();
     virtual int defense_roll(int);
     virtual void recover_strength();
     virtual ~Medusa();
};

#endif