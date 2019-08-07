/**************************************************************************
** Program name: Project 3  - HarryPotter.hpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This is the header file for harry potter. It will hold the
**               prototypes for the constructor, attack rolls, strength, and
**               the destructor as well.
****************************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Characters.hpp"

class HarryPotter : public Characters 
{
public:
     HarryPotter();
     virtual int attack_roll();
     virtual int defense_roll(int);
     virtual void recover_strength();
     virtual ~HarryPotter();
private:
     int harryLives;
};

#endif