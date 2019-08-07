/**************************************************************************
** Program name: Project 3  - Characters.hpp
** Author:       Jacob Hendry
** Date:         5/12/2019
** Description:  This is the header file for the characters. It will hold the
**               prototypes for the constructor, attack rolls, strength, die
**               amount rolled for attack and defense, and the destructor
****************************************************************************/
#ifndef CHARACTERS_HPP
#define CHARACTERS_HPP

using std::string;

class Characters 
{
protected:
     int strength;
     int armor;
     int defPoints;
     string name;
     string specialAttack;
     int dieNumAttack;
     int dieNumDefense;
     int dieSidesAttack;
     int dieSidesDefense;

public:
     Characters();
     virtual int attack_roll() = 0;
     virtual void recover_strength() = 0;
     std::string get_name();
     int get_strength();
     int get_armor();
     int get_defPoints();
     std::string get_special();
     virtual int defense_roll(int);
     int die_roll(int dieNum, int dieSides);
     bool defeated();
     virtual ~Characters();
};

#endif