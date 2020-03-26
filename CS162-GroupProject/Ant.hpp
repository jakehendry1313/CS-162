/*********************************************************************
** CS 162: Group Project
**
** Program: predatorPrey
** File:    Ant.hpp
** Author:  Casey Levy
** Date:    2019-04-26
**------------------------------------------------------------------
** This is the header file for the Ant class.  This class
** has functions to move and breed the bug. It is derived from
** Critter.
********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP
#include "Critter.hpp"

class Ant : public Critter
 {
    public:

      Ant(int startingX, int startingY);

      // Override functions from Critter
      Critter* breed(); 							
      bool getBreedStatus(); 
      bool move();
	  bool starve();
      int getType();

      ~Ant() {};

 };
 
#endif
