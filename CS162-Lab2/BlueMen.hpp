/**************************************************************************
** Program name: Project 3  - BlueMen.hpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This is the header file for the bluemen. It will hold the
**               prototypes for the constructor, attack rolls, strength, and
**               the destructor as well.
****************************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Characters.hpp"

class BlueMen : public Characters 
{
public:
     BlueMen();
     virtual int attack_roll();
     virtual int defense_roll(int);
     virtual void recover_strength();
     virtual ~BlueMen();
};

#endif