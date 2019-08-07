/**************************************************************************
** Program name: Project 3  - Barbarian.hpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This is the header file for the barbarian. It will hold the
**               prototypes for the constructor, attack rolls, strength, and
**               the destructor as well.
****************************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Characters.hpp"

class Barbarian : public Characters \
{
public:
     Barbarian();
     virtual int attack_roll();
     virtual void recover_strength();
     virtual ~Barbarian();
};

#endif